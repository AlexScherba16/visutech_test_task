//
// Created by alexander on 26.06.2021.
//

#include <fstream>
#include <memory>

#include "DefaultApplication.h"
#include "parser/CommandLineParser.h"
#include "replace/InWordReplaceStrategy.h"
#include "sort/IgnoreCaseSortStrategy.h"

namespace Application {

    int DefaultApplication::run(int argc, char *argv[]) {
        using namespace std;
        using Replace::IReplaceble, Replace::InWordReplaceStrategy;
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

        // create strings storage
        vector<string> strings;
        strings.reserve(500000);

        // create replace word replace strategy
        unique_ptr<IReplaceble> replaceStrategy = make_unique<InWordReplaceStrategy>(word);

        // create sort strategy
        unique_ptr<ISortable> sortStrategy = make_unique<IgnoreCaseSortStrategy>();

        // fill strings vector
        string fileString;
        while(!reader.eof()) {
            getline(reader, fileString);
            replaceStrategy->replace(fileString);
            strings.push_back(fileString);
        }

        // sort data and write text file
        sortStrategy->sort(strings);
        for(const auto& item : strings)
            writer << item;

        // flush buffered data
        writer.flush();

        // close files
        reader.close();
        writer.close();

        return 0;
    }
}
