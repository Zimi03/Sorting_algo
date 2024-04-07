#ifndef SORTING_ALGORITHMS_QUICKSORT_H
#define SORTING_ALGORITHMS_QUICKSORT_H

#include <iostream>
#include <vector>
#include <random>

template<typename T>
class QuickSort {
public:
    void sort(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end) {
        if (begin != end && std::distance(begin, end) > 1) {
            auto pivot = partition(begin, end);
            sort(begin, pivot);
            sort(pivot + 1, end);
        }
    }

private:
    typename std::vector<T>::iterator partition(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end) {
        std::random_device rand;
        std::mt19937 gen(rand());
        std::uniform_int_distribution<> dis(0, std::distance(begin, end) - 1);
        auto pivotIndex = dis(gen);
        auto pivot = *(begin + pivotIndex);

        std::iter_swap(begin, begin+pivotIndex);

        auto left = begin + 1;
        auto right = end - 1;

        while (left <= right) {
            while (left <= right && *left < pivot) ++left;
            while (left <= right && *right >= pivot) --right;
            if (left < right) {
                std::iter_swap(left, right);
            }
        }
        std::iter_swap(begin, right);
        return right;
    }
};

#endif //SORTING_ALGORITHMS_QUICKSORT_H
