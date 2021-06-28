//
// Created by alexander on 27.06.2021.
//

#include <memory>
#include <boost/thread/thread.hpp>

#include "TreadedApplication.h"
#include "parser/CommandLineParser.h"
#include "replace/InWordReplaceStrategy.h"
#include "sort/IgnoreCaseSortStrategy.h"


namespace Application {

    void TreadedApplication::_producer(const std::string& word, std::ifstream& reader) {
        /* !!! JUST FOR DEMO NO EXCEPTION PROCESSING !!! */
        using Replace::IReplaceble, Replace::InWordReplaceStrategy;

        // create replace word replace strategy
        std::unique_ptr<IReplaceble> replaceStrategy = std::make_unique<InWordReplaceStrategy>(word);

        std::string fileString;
        while(!reader.eof()) {
            getline(reader, fileString);
            replaceStrategy->replace(fileString);
            while (!_dataQueue.push(fileString));
        }
    }

    void TreadedApplication::_consumer(std::ofstream& writer) {
        /* !!! JUST FOR DEMO NO EXCEPTION PROCESSING !!! */
        using Sort::ISortable, Sort::IgnoreCaseSortStrategy;

        // create sort strategy
        std::unique_ptr<ISortable> sortStrategy = std::make_unique<IgnoreCaseSortStrategy>();

        // create strings storage
        std::vector<std::string> strings(500000);
        std::string fileString;

        while (!_done) {
            while (_dataQueue.pop(fileString)) {
                fileString.append(fileString);
            }
        }

        while (_dataQueue.pop(fileString)) {
            fileString.append(fileString);
        }

        // sort data and write text file
        sortStrategy->sort(strings);
        for(const auto& item : strings)
            writer << item;
    }

    int TreadedApplication::run(int argc, char *argv[]) {
        using namespace std;

        cout << "boost::lockfree::queue is ";
        if (!_dataQueue.is_lock_free())
            cout << "not ";
        cout << "lockfree" << endl;

        using Sort::ISortable, Sort::IgnoreCaseSortStrategy;

        // parse command line
        Parser::CommandLineParser parser;
        const auto [src, word, dest] = parser.parse(argc, argv);

        cout << "SOURCE " << src << endl;
        cout << "WORD   " << word << endl;
        cout << "DEST   " << dest << endl;

        // open source file
        ifstream reader (src, ios::in);
        if(!reader.is_open())
            throw ApplicationException("Can't open source file\t" + src);

        // open destination file
        ofstream writer(dest, ios::out);
        if(!writer.is_open())
            throw ApplicationException("Can't open dest file\t" + dest);

        // create data producer
        boost::thread producerThread(&TreadedApplication::_producer,
                                      this, boost::cref(word),
                                      boost::ref(reader));
        // create data consumer
        boost::thread consumerThread(&TreadedApplication::_consumer,
                                     this, boost::ref(writer));
        // run threads
        producerThread.join();
        _done = true;
        consumerThread.join();

        // flush buffered data
        writer.flush();

        // close files
        reader.close();
        writer.close();
        return 0;
    }
}

