//
// Created by mikec_g1kgiu8 on 3/2/2022.
//
#include <iostream>
#include "SortingAlgorithms.h"

using namespace std;

int main() {
    int tester[] = {0, 55, 6, 3, 45, 99, 992, 2, 3, 1};
    SortingAlgorithms theSorter;

    theSorter.insertionSort(tester, 0, 10);

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

    int tester4[] = {0, 55, 6, 3, 45, 99, 992, 2, 3, 1};

    theSorter.shellSort(tester4, 10);

    for (int i = 0; i < 10; i++) {
        cout << tester4[i] << " ";
    }
    cout << endl;

    int tester5[] = {0, 55, 6, 3, 45, 99, 992, 2, 3, 1, 77, 8989, 1, 2, 3, 4, 5, 6, 7};

    theSorter.introSort(tester5, 0, 19);
//    cout << sizeof(tester5) / sizeof(tester5[0]) << endl;
//    int maxdepth = log(19) * 2;
//    introsort(tester5, tester5, tester5 + 19 - 1, maxdepth);

    for (int i = 0; i < 19; i++) {
        cout << tester5[i] << " ";
    }
    cout << endl;

    int tester6[] = {0, 55, 6, 3, 45, 99, 992, 2, 3, 1};

    theSorter.timSort(tester6, 10);

    for (int i = 0; i < 10; i++) {
        cout << tester6[i] << " ";
    }
    cout << endl;


}