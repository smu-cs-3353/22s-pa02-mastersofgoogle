//
// Created by mikec_g1kgiu8 on 3/3/2022.
//

#ifndef INC_22S_PA02_MASTERSOFGOOGLE_SORTINGALGORITHMS_H
#define INC_22S_PA02_MASTERSOFGOOGLE_SORTINGALGORITHMS_H

#include <random>
#include <algorithm>
#include <iostream>

using namespace std;

template <typename T>
class SortingAlgorithms {
    private:
        //Partition and Swap functions for Randomized QuickSort and IntroSort
        int partition(T[], int, int);
        void swap(T*, T*);

        //Merge function for MergeSort
        void merge(T[], int, int, int);

        //Private, recursive IntroSort function
        void introSort(T[], T*, T*, int);

    public: //FIXME temporarily public (?)
        void insertionSort(T[], int, int);
        void randomizedQuickSort(T[], int, int);
        void mergeSort(T[], int, int);
        void shellSort(T[], int);
        void introSort(T[], T*, T*);
        void timSort(T[], int);

};

//Inspired by code found at: https://www.geeksforgeeks.org/insertion-sort/ and https://www.techiedelight.com/introsort-algorithm/
template <typename T>
void SortingAlgorithms<T>::insertionSort(T theArray[], int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        T key = theArray[i];
        int j = i - 1;

        while (j >= low && theArray[j] > key) {
            theArray[j + 1] = theArray[j];
            j -= 1;
        }
        theArray[j + 1] = key;
    }
}

//Inspired by code found at: https://www.geeksforgeeks.org/quicksort-using-random-pivoting/
template <typename T>
void SortingAlgorithms<T>::randomizedQuickSort(T theArray[], int low, int high) {
    if (low < high) {
        int partitionIndex = partition(theArray, low, high);

        randomizedQuickSort(theArray, low, partitionIndex - 1);
        randomizedQuickSort(theArray, partitionIndex + 1, high);
    }
}

template <typename T>
int SortingAlgorithms<T>::partition(T theArray[], int low, int high) {
    int randomNum = (rand() % (high - low)) + low;

    swap(&theArray[randomNum], &theArray[high]);

    T pivot = theArray[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (theArray[j] <= pivot) {
            i++;
            swap(&theArray[i], &theArray[j]);
        }
    }

    swap(&theArray[i + 1], &theArray[high]);
    return i + 1;
}

template <typename T>
void SortingAlgorithms<T>::swap(T* a, T* b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

//Inspired by code found at: https://www.geeksforgeeks.org/merge-sort/
template <typename T>
void SortingAlgorithms<T>::mergeSort(T theArray[], int left, int right) {
    if (left >= right) {
        return;
    }

    int middle = left + (right - left) / 2;

    mergeSort(theArray, left, middle);
    mergeSort(theArray, middle + 1, right);

    merge(theArray, left, middle, right);

}

template <typename T>
void SortingAlgorithms<T>::merge(T theArray[], int left, int middle, int right) {
    int subArray1 = middle - left + 1;
    int subArray2 = right - middle;

    T* leftArray = new T[subArray1];
    T* rightArray = new T[subArray2];

    for (int i = 0; i < subArray1; i++) {
        leftArray[i] = theArray[left + i];
    }

    for (int i = 0; i < subArray2; i++) {
        rightArray[i] = theArray[middle + i + 1];
    }

    int subIndex1 = 0;
    int subIndex2 = 0;

    int mergedIndex = left;

    while (subIndex1 < subArray1 && subIndex2 < subArray2) {
        if (leftArray[subIndex1] <= rightArray[subIndex2]) {
            theArray[mergedIndex] = leftArray[subIndex1];
            subIndex1++;
        } else {
            theArray[mergedIndex] = rightArray[subIndex2];
            subIndex2++;
        }
        mergedIndex++;
    }

    while (subIndex1 < subArray1) {
        theArray[mergedIndex] = leftArray[subIndex1];
        subIndex1++;
        mergedIndex++;
    }

    while (subIndex2 < subArray2) {
        theArray[mergedIndex] = rightArray[subIndex2];
        subIndex2++;
        mergedIndex++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

//Inspired by pseudo-code found at: https://www.tutorialspoint.com/data_structures_algorithms/shell_sort_algorithm.htm
template <typename T>
void SortingAlgorithms<T>::shellSort(T theArray[], int size) {
    int interval = 1;

    while (interval < size / 3) {
        interval = interval * 3 + 1;
    }

    while (interval > 0) {
        for (int i = interval; i < size; i++) {
            T value = theArray[i];
            int j = i;

            while (j >= interval && theArray[j - interval] > value) {
                theArray[j] = theArray[j - interval];
                j = j - interval;
            }

            theArray[j] = value;
        }

        interval = (interval - 1) / 3;
    }
}

//Inspired by code found at: https://www.techiedelight.com/introsort-algorithm/
template <typename T>
void SortingAlgorithms<T>::introSort(T theArray[], T* beginning, T* end) {
    int depthLimit = 2 * log(end - beginning);

    introSort(theArray, beginning, end, depthLimit);
}

template <typename T>
void SortingAlgorithms<T>::introSort(T theArray[], T* beginning, T* end, int depthLimit) {
    int size = end - beginning;

    if (size < 16) {
        insertionSort(theArray, beginning - theArray, end - theArray);
        return;
    } else if (depthLimit == 0) {
        make_heap(beginning, end + 1);
        sort_heap(beginning, end + 1);
        return;
    } else {

        T* partitionIndex = theArray + partition(theArray, beginning - theArray, end - theArray); //introSortPartition(theArray, beginning - theArray, end - theArray);

        introSort(theArray, beginning, partitionIndex - 1, depthLimit - 1);
        introSort(theArray, partitionIndex + 1, end, depthLimit - 1);

        return;
    }
}

//Inspired by code found at: https://www.geeksforgeeks.org/timsort/
template <typename T>
void SortingAlgorithms<T>::timSort(T theArray[], int size) {
    int run = 32;
    for (int i = 0; i < size; i += run) { //FIXME can change 32 to 64 (or a larger power of 2)
        insertionSort(theArray, i, std::min((i + run - 1), (size - 1))); //FIXME change 32 here too
    }

    for (int i = run; i < size; i *= 2) {
        for (int left = 0; left < size; left += i * 2) {
            int middle = left + i - 1;
            int right = std::min((left + 2 * i - 1), (size - 1));

            if (middle < right) {
                merge(theArray, left, middle, right);
            }
        }
    }
}







#endif //INC_22S_PA02_MASTERSOFGOOGLE_SORTINGALGORITHMS_H
