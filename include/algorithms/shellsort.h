#ifndef SORTING_ALGORITHMS_SHELLSORT_H
#define SORTING_ALGORITHMS_SHELLSORT_H

#include <vector>
#include "abstractsort.h"

// sortowanie Shella

template <typename T>
class ShellSort: public AbstractSort<T>
{
public:
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end)
    {
    };
};
#endif //SORTING_ALGORITHMS_SHELLSORT_H
