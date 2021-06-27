//
// Created by alexander on 26.06.2021.
//

#include "parser/CommandLineParser.h"
#include <boost/program_options.hpp>

#include <iostream>

namespace Parser {
    using namespace std;

    tuple<
    /*src*/ string,
    /*word*/ string,
    /*dest*/ string>
    CommandLineParser::parse(int argc, char *argv[]) {

        if (argc <= 0)
            throw ParserException("argc <= 0");
        if (argv == nullptr)
            throw ParserException("argv == nullptr");

        namespace po = boost::program_options;
        string src, word, dest;

        try {
            // create option descriptor and append options
            po::options_description desc("Allowed options");
            desc.add_options()
                    // First parameter describes option name/short name
                    // The second is parameter to option
                    // The third is description
                    ("help,h", "print usage message")
                    ("src,s", po::value<string>(&src)->required(), "source file path")
                    ("word,w", po::value<string>(&word)->required(), "the word to be removed from the source file")
                    ("dest,d", po::value<string>(&dest)->required(), "destination file path");

            // create options map and set input values
            po::variables_map vm;
            store(parse_command_line(argc, argv, desc), vm);

            if (vm.count("help")) {
                cout << desc << std::endl;
                throw ParserException("print --help parameter");
            }

            /* throw exception if now required params */
            po::notify(vm);

        } catch(po::error& e) {
            throw ParserException(e.what());
        }

        // return params tuple if all is ok
        return make_tuple(src, word, dest);
    }
}
