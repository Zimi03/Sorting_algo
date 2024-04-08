#include <iostream>
#include <vector>
#include <map>
#include <chrono>
#include <ctime>

#include "tools/helpers.hpp"
#include "tools/results.hpp"
#include "tools/dataexporter.hpp"
#include "algorithms/abstractsort.h"
#include "algorithms/quicksort.h"
#include "algorithms/introsort.h"
#include "algorithms/mergesort.h"

 std::vector<int> stacks = {10000, 50000, 100000, 500000, 1000000};
//std::vector<int> stacks = {10000, 50000, 100000, 1000000};
std::vector<float> presortPercentages = {0, 25, 50, 75, 95, 99, 99.7f, -100};
//std::vector<float> presortPercentages = {0};
int main(int argc, char* argv[])
{
    const int MEASUREMENTS_COUNT = 100;
    std::vector<Results> benchmarks;
    std::map<std::string, AbstractSort<int>*> sorts;

    sorts["introsort"] = new IntroSort<int>();
    sorts["mergesort"] = new MergeSort<int>();
    sorts["quicksort"] = new QuickSort<int>();

    for (auto sort : sorts) {
        for (auto stack : stacks) {
            for (auto presortPercentage : presortPercentages) {
                Results result(sort.first, stack, presortPercentage);
                std::cout << "Running " << sort.first << " with " << stack << " elements and " << presortPercentage << "% presorted" << std::endl;

                for (int i = 0; i < MEASUREMENTS_COUNT; i++) {
                    std::vector<int> data = Helpers::generateArray(stack);
                    Helpers::preSort(data, presortPercentage);
                    auto dataBegin = data.begin();
                    auto dataEnd = data.end();

                    const auto timeStart = std::chrono::high_resolution_clock::now();
                    sort.second->sort(dataBegin, dataEnd);
                    const auto timeEnd = std::chrono::high_resolution_clock::now();
                    const auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart);
                    result.push(duration.count());
                }
                benchmarks.push_back(result);
            }
        }
    }

    std::cout << std::endl;

    DataExporter exporter(benchmarks);
    exporter.generate();

    return 0;
}
