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

//Inspired by code found at: https://www.geeksforgeeks.org/quicksort-using-random-pivoting/
void SortingAlgorithms::randomizedQuickSort(int theArray[], int low, int high) {
    if (low < high) {
        int partitionIndex = partition(theArray, low, high);

        randomizedQuickSort(theArray, low, partitionIndex - 1);
        randomizedQuickSort(theArray, partitionIndex + 1, high);
    }
}

int SortingAlgorithms::partition(int theArray[], int low, int high) {
    int randomNum = (rand() % (high - low)) + low;

    swap(&theArray[randomNum], &theArray[high]);

    int pivot = theArray[high];
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

void SortingAlgorithms::swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Inspired by code found at: https://www.geeksforgeeks.org/merge-sort/
void SortingAlgorithms::mergeSort(int theArray[], int left, int right) {
    if (left >= right) {
        return;
    }

    int middle = left + (right - left) / 2;

    mergeSort(theArray, left, middle);
    mergeSort(theArray, middle + 1, right);

    merge(theArray, left, middle, right);

}

void SortingAlgorithms::merge(int theArray[], int left, int middle, int right) {
    int subArray1 = middle - left + 1;
    int subArray2 = right - middle;

    int* leftArray = new int[subArray1];
    int* rightArray = new int[subArray2];

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

