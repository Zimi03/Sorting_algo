#ifndef SORTING_ALGORITHMS_HEAPSORT_H
#define SORTING_ALGORITHMS_HEAPSORT_H

#include <vector>
#include "abstractsort.h"

// sortowanie przez kopcowanie. Należy samodzielnie zaimplementować odpowiedni kopiec, który kopcuje bez użycia dodatkowej pamięci.

template <typename T>
class HeapSort: public AbstractSort<T>
{
public:
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end) {
        buildHeap(start, end);

        for (auto it = end - 1; it > start; --it) {
            std::swap(*start, *it);
            heapify(start, it, start);
        }
    }

private:
    void buildHeap(
        typename std::vector<T>::iterator start,
        typename std::vector<T>::iterator end
    ) {
        int n = std::distance(start, end);
        for (int i = n / 2 - 1; i >= 0; --i) {
            heapify(start, end, start + i);
        }
    }

    void heapify(
        typename std::vector<T>::iterator start,
        typename std::vector<T>::iterator end,
        typename std::vector<T>::iterator root
    ) {
        auto largest = root;
        auto left = start + std::distance(start, root) * 2 + 1;
        auto right = left + 1;

        if (left < end && *left > *largest)
            largest = left;
        if (right < end && *right > *largest)
            largest = right;

        if (largest != root) {
            std::swap(*root, *largest);
            heapify(start, end, largest);
        }
    }
};

#endif //SORTING_ALGORITHMS_HEAPSORT_H
