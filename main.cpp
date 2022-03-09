//
// Created by mikec_g1kgiu8 on 3/2/2022.
//
#include <iostream>
#include <random>
#include "SortingAlgorithms.h"

using namespace std;

int main() {
    SortingAlgorithms theSorter;

    int tester1[1000];
    int tester2[1000];
    int tester3[1000];
    int tester4[1000];
    int tester5[1000];
    int tester6[1000];

    cout << "Unsorted" << endl;
    for (int i = 0; i < 1000; i++) {
        int randomNum = rand() % 1000;
        tester1[i] = randomNum;
        tester2[i] = randomNum;
        tester3[i] = randomNum;
        tester4[i] = randomNum;
        tester5[i] = randomNum;
        tester6[i] = randomNum;

        cout << randomNum << " ";
    }
    cout << endl;

    theSorter.insertionSort(tester1, 0, 999);
    cout << "Insertion Sort" << endl;

    for (int i = 0; i < 1000; i++) {
        cout << tester1[i] << " ";
    }
    cout << endl;

    theSorter.randomizedQuickSort(tester2, 0, 999);
    cout << "Quick Sort" << endl;

    for (int i = 0; i < 1000; i++) {
        cout << tester2[i] << " ";
    }
    cout << endl;

    theSorter.mergeSort(tester3, 0, 999);
    cout << "Merge Sort" << endl;

    for (int i = 0; i < 1000; i++) {
        cout << tester3[i] << " ";
    }
    cout << endl;

    theSorter.shellSort(tester4, 1000);
    cout << "Shell Sort" << endl;

    for (int i = 0; i < 1000; i++) {
        cout << tester4[i] << " ";
    }
    cout << endl;

    theSorter.introSort(tester5, tester5, tester5 + 999);
    cout << "Intro Sort" << endl;

    for (int i = 0; i < 1000; i++) {
        cout << tester5[i] << " ";
    }
    cout << endl;

    theSorter.timSort(tester6, 1000);
    cout << "Tim Sort" << endl;

    for (int i = 0; i < 1000; i++) {
        cout << tester6[i] << " ";
    }
    cout << endl;

}