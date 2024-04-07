#ifndef SORTING_ALGORITHMS_MERGESORT_H
#define SORTING_ALGORITHMS_MERGESORT_H

#include <iostream>
#include <vector>

template <typename T>
class MergeSort {
public:
   void sort(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end) {
       if (std::distance(start, end) > 1) {
           auto mid = start + std::distance(start, end) / 2;

           sort(start, mid);
           sort(mid, end);
           merge(start, mid, end);
       }
   }
private:
    static void merge(typename std::vector<T>::iterator start,
                      typename std::vector<T>::iterator mid,
                      typename std::vector<T>::iterator end) {

        std::vector<T> temp(std::distance(start,end));
        auto left = start;
        auto right = mid;
        auto tempIter = temp.begin();

            while (left < mid && right < end) {
                if (*left <= *right) {
                    *tempIter++ = std::move(*left++);
                } else {
                    *tempIter++ = std::move(*right++);
                }
            }

            // kopiowanie pozostałych elementów
            while(left < mid){
                *tempIter++ = std::move(*left++);
            }
            while (right<end){
                *tempIter++ = std::move(*right++);
            }
            //kopiowanie wartości temp do oryginalnej tablicy
            std::move(temp.begin(), temp.end(), start);
    }
};

#endif //SORTING_ALGORITHMS_MERGESORT_H
