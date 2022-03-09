//
// Created by mikec_g1kgiu8 on 3/3/2022.
//

#ifndef INC_22S_PA02_MASTERSOFGOOGLE_SORTINGALGORITHMS_H
#define INC_22S_PA02_MASTERSOFGOOGLE_SORTINGALGORITHMS_H

#include <random>
#include <algorithm>
#include <iostream>

using namespace std;

class SortingAlgorithms {
    private:
        //Partition and Swap functions for Randomized QuickSort and IntroSort
        int partition(int[], int, int);
        void swap(int*, int*);

        //Merge function for MergeSort
        void merge(int[], int, int, int);

        //Private, recursive IntroSort function
        void introSort(int[], int*, int*, int);

    public: //FIXME temporarily public (?)
        void insertionSort(int[], int, int);
        void randomizedQuickSort(int[], int, int);
        void mergeSort(int[], int, int);
        void shellSort(int[], int);
        void introSort(int[], int*, int*);
        void timSort(int[], int);

};


#endif //INC_22S_PA02_MASTERSOFGOOGLE_SORTINGALGORITHMS_H
