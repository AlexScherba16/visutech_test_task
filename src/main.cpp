#include <iostream>
#include <iomanip>
#include <memory>
#include <chrono>

#include "application/DefaultApplication.h"
#include "application/TreadedApplication.h"

int main(int argc, char *argv[]){
    using Application::IRunnable, Application::DefaultApplication, Application::TreadedApplication;

    try {
        // create default application strategy
        std::unique_ptr<IRunnable> app = std::make_unique<DefaultApplication>();

        /* slower than default
        std::unique_ptr<IRunnable> app = std::make_unique<TreadedApplication>();
         */

        auto start = std::chrono::high_resolution_clock::now();
        int result = app->run(argc, argv);
        auto end = std::chrono::high_resolution_clock::now();

        // calculating total time taken by the program.
        double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        time_taken *= 1e-9;

        std::cout << "program time execution: " << std::fixed << time_taken << std::setprecision(9);
        std::cout << " sec" << std::endl;
        return result;

    } catch(const std::exception& ex) {
        std::cout << ex.what() << std::endl;
        return -1;
    }
}
