#ifndef SORTING_ALGORITHMS_ABSTRACT_SORT_H
#define SORTING_ALGORITHMS_ABSTRACT_SORT_H

#include <vector>

template<typename T>
class AbstractSort {
public:
    virtual void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end) = 0;
};

#endif //SORTING_ALGORITHMS_ABSTRACT_SORT_H
