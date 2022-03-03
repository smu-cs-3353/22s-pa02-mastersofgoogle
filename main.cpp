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
        cout << tester[i] << endl;
    }

}