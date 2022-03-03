//
// Created by mikec_g1kgiu8 on 3/3/2022.
//

#include "SortingAlgorithms.h"

//Inspired by code found at: https://www.geeksforgeeks.org/insertion-sort/
void SortingAlgorithms::insertionSort(int theArray[], int size) {
    for (int i = 1; i < size; i++) {
        int key = theArray[i];
        int j = i - 1;

        while (j >= 0 && theArray[j] > key) {
            theArray[j + 1] = theArray[j];
            j = j - 1;
        }
        theArray[j + 1] = key;
    }
}
