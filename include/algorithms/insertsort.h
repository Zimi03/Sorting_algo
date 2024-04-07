#ifndef SORTING_ALGORITHMS_INSERTSORT_H
#define SORTING_ALGORITHMS_INSERTSORT_H

#include <vector>
#include "abstractsort.h"

// sortowanie przez wstawianie

template <typename T>
class InsertSort: public AbstractSort<T>
{
public:
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end)
    {
    };
};

#endif //SORTING_ALGORITHMS_INSERTSORT_H
