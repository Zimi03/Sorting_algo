//
// Created by Szymon on 21.03.2024.
//
#include<iostream>
#include<vector>
#ifndef SORTING_ALGORITHMS_MERGE_2_H
#define SORTING_ALGORITHMS_MERGE_2_
class mergeXD{

    static void sort(std::vector<int>& arr) {
        mergeSort(arr, 0, arr.size() - 1);
    }

private:
    static void mergeSort(std::vector<int>& arr, int low, int XD) {
        if (low < XD) {
            int mid = low + (XD - low) / 2;

            mergeSort(arr, low, mid);
            mergeSort(arr, mid + 1, XD);

            merge(arr, low, mid, XD);
        }
    }

    static void merge(std::vector<int>& arr, int low, int mid, int XD) {
        int n1 = mid - low + 1;
        int n2 = XD - mid;

        std::vector<int> left(n1);
        std::vector<int> right(n2);

        for (int i = 0; i < n1; ++i)
            left[i] = arr[low + i];
        for (int j = 0; j < n2; ++j)
            right[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = low;

        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                arr[k] = left[i];
                ++i;
            } else {
                arr[k] = right[j];
                ++j;
            }
            ++k;
        }

        while (i < n1) {
            arr[k] = left[i];
            ++i;
            ++k;
        }

        while (j < n2) {
            arr[k] = right[j];
            ++j;
            ++k;
        }
    }
};
#endif //SORTING_ALGORITHMS_MERGE_2_H
