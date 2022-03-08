//
// Created by mikec_g1kgiu8 on 3/2/2022.
//
#include <iostream>
#include "SortingAlgorithms.h"

using namespace std;

int main() {
    int tester[] = {0, 55, 6, 3, 45, 99, 992, 2, 3, 1};
    SortingAlgorithms theSorter;

    theSorter.insertionSort(tester, 10);

    for (int i = 0; i < 10; i++) {
        cout << tester[i] << " ";
    }
    cout << endl;

    int tester2[] = {0, 55, 6, 3, 45, 99, 992, 2, 3, 1};

    theSorter.randomizedQuickSort(tester2, 0, 9);

    for (int i = 0; i < 10; i++) {
        cout << tester2[i] << " ";
    }
    cout << endl;

    int tester3[] = {0, 55, 6, 3, 45, 99, 992, 2, 3, 1};

    theSorter.mergeSort(tester3, 0, 9);

    for (int i = 0; i < 10; i++) {
        cout << tester3[i] << " ";
    }
    cout << endl;
}