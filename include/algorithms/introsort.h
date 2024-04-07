#ifndef SORTING_ALGORITHMS_INTROSORT_H
#define SORTING_ALGORITHMS_INTROSORT_H

#include <vector>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
#include <cmath>

#include "heapsort.h"
#include "mergesort.h"
#include "quicksort.h"
#include "abstractsort.h"

// sortowanie introspektywne

template<typename T>
class IntroSort: public AbstractSort<T>
{
public:

    IntroSort() = default;

    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end) {
        const int size = std::distance(start, end);
        const int maxDepth = 2 * log(size);

        this->figureOut(start, end, maxDepth);
        this->mergeSort.sort(start, end);
    };

private:
    void figureOut(
        typename std::vector<T>::iterator start,
        typename std::vector<T>::iterator end,
        int maxDepth
    ) {
        if (end - start) {
            return;
        }

        if (maxDepth == 0) {
            this->heapSort.sort(start, end);
        } else {
            --maxDepth;
            auto pivot = this->quickSort.partition(start, end);
            this->figureOut(start, pivot, maxDepth);
            this->figureOut((pivot + 1), end, maxDepth);
        }
    }

private:
    HeapSort<T> heapSort;
    MergeSort<T> mergeSort;
    QuickSort<T> quickSort;
};

#endif //SORTING_ALGORITHMS_INTROSORT_H
