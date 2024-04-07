#include <iostream>
#include <vector>
#include <map>
#include <chrono>
#include <ctime>

#include "tools/helpers.hpp"
#include "tools/results.hpp"
#include "algorithms/abstractsort.h"
#include "algorithms/quicksort.h"
#include "algorithms/introsort.h"
#include "algorithms/mergesort.h"

// std::vector<int> stacks = {10000, 50000, 100000, 500000, 1000000};
std::vector<int> stacks = {10000, 50000};
std::vector<float> progressChecks = {25, 50, 75, 95, 99, 99.7f};

int main(int argc, char* argv[])
{
    std::map<std::string, std::map<int, Results>> benchmarks;
    std::map<std::string, AbstractSort<int>*> sorts;

    sorts["introsort"] = new IntroSort<int>();
    sorts["mergesort"] = new MergeSort<int>();
    // sorts["quicksort"] = new QuickSort<int>();

    for (auto sort : sorts) {
        for (auto stack : stacks) {
            Results result;
            std::cout << "Running " << sort.first << " with " << stack << " elements" << std::endl;

            for (int i = 0; i < 100; i++) {
                std::vector<int> data = Helpers::generateArray(stack);
                auto dataBegin = data.begin();
                auto dataEnd = data.end();

                const auto timeStart = std::chrono::high_resolution_clock::now();
                sort.second->sort(dataBegin, dataEnd);
                const auto timeEnd = std::chrono::high_resolution_clock::now();
                const auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart);
                result.push(duration.count());
            }

            benchmarks[sort.first][stack] = result;
        }
    }

    for (auto sort : benchmarks) {
        std::cout << sort.first << std::endl;

        for (auto stack : sort.second) {
            std::cout << stack.first << " elements: ";
            std::cout << "Average: " << stack.second.average() << "ms" << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}
