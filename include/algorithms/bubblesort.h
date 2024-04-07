#ifndef SORTING_ALGORITHMS_BUBBLESORT_H
#define SORTING_ALGORITHMS_BUBBLESORT_H

#include <vector>
#include "abstractsort.h"

// sortowanie bąbelkowe

template <typename T>
class BubbleSort: public AbstractSort<T>
{
public:
    void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end)
    {
    };
};

#endif //SORTING_ALGORITHMS_BUBBLESORT_H
