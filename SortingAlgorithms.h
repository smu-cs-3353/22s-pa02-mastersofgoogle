//
// Created by mikec_g1kgiu8 on 3/3/2022.
//

#ifndef INC_22S_PA02_MASTERSOFGOOGLE_SORTINGALGORITHMS_H
#define INC_22S_PA02_MASTERSOFGOOGLE_SORTINGALGORITHMS_H

#include <random>
#include <iostream>

class SortingAlgorithms {
    private:
        //Partition and Swap functions for Randomized QuickSort
        int partition(int[], int, int);
        void swap(int*, int*);

        //Merge function for MergeSort
        void merge(int[], int, int, int);

    public: //FIXME temporarily public (?)
        void insertionSort(int[], int);
        void randomizedQuickSort(int[], int, int);
        void mergeSort(int[], int, int);
        void shellSort();
        void introSort();
        void timSort();

    //public:

};


#endif //INC_22S_PA02_MASTERSOFGOOGLE_SORTINGALGORITHMS_H
