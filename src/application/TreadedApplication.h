//
// Created by alexander on 27.06.2021.
//

#ifndef VISUTECH_TASK_TREADEDAPPLICATION_H
#define VISUTECH_TASK_TREADEDAPPLICATION_H

#include <fstream>
#include <boost/lockfree/spsc_queue.hpp>
#include <boost/atomic.hpp>

#include "application/Application.h"


namespace Application {

    class TreadedApplication final : public IRunnable {
        boost::atomic<bool> _done;
        boost::lockfree::spsc_queue< std::string, boost::lockfree::capacity<2048> > _dataQueue;

        void _producer(const std::string& word, std::ifstream& reader);
        void _consumer(std::ofstream& writer);


    public:
        TreadedApplication(): _done (false) {};
        ~TreadedApplication() = default;

        int run(int argc, char *argv[]) override;
    };
}

#endif //VISUTECH_TASK_TREADEDAPPLICATION_H
