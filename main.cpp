//
// Created by mikec_g1kgiu8 on 3/2/2022.
//
#include <iostream>
#include <random>
#include <fstream>
#include "SortingAlgorithms.h"

using namespace std;

int main() {
//    SortingAlgorithms<int> theSorter1;
//    SortingAlgorithms<string> theSorter2;
//
//    int tester1[5] = {2, 33, 1, 5, 9};
//    string tester2[5] = {"a", "boy", "yellow", "boi", "WAterMeLON"};
//
//    //theSorter1.insertionSort(tester1, 0, 4);
//    //theSorter2.timSort(tester2, 5);
//
//    for (int i = 0; i < 5; i++) {
//        cout << tester2[i] << endl;
//    }

    SortingAlgorithms<string> theSorter;

    ifstream input("../DatasetGeneration/string_datasets/randomized_no_duplicates_1000.txt", ios::in);
    string words[1000];

    cout << "Unsorted" << endl;
    for (int i = 0; i < 1000; i++) {
        input >> words[i];
        cout << words[i] << " ";
    }
    cout << endl;

    theSorter.insertionSort(words, 0, 999);
    cout << "Insertion Sort" << endl;

    for (int i = 0; i < 1000; i++) {
        cout << words[i] << " ";
    }
    cout << endl;
    input.close();

    ifstream input2("../DatasetGeneration/string_datasets/randomized_no_duplicates_1000.txt", ios::in);

    for (int i = 0; i < 1000; i++) {
        input2 >> words[i];
    }

    theSorter.randomizedQuickSort(words, 0, 999);
    cout << "Quick Sort" << endl;

    for (int i = 0; i < 1000; i++) {
        cout << words[i] << " ";
    }
    cout << endl;
    input2.close();

    ifstream input3("../DatasetGeneration/string_datasets/randomized_no_duplicates_1000.txt", ios::in);

    for (int i = 0; i < 1000; i++) {
        input3 >> words[i];
    }

    theSorter.mergeSort(words, 0, 999);
    cout << "Merge Sort" << endl;

    for (int i = 0; i < 1000; i++) {
        cout << words[i] << " ";
    }
    cout << endl;
    input3.close();

    ifstream input4("../DatasetGeneration/string_datasets/randomized_no_duplicates_1000.txt", ios::in);

    for (int i = 0; i < 1000; i++) {
        input4 >> words[i];
    }


    theSorter.shellSort(words, 1000);
    cout << "Shell Sort" << endl;

    for (int i = 0; i < 1000; i++) {
        cout << words[i] << " ";
    }
    cout << endl;
    input4.close();

    ifstream input5("../DatasetGeneration/string_datasets/randomized_no_duplicates_1000.txt", ios::in);

    for (int i = 0; i < 1000; i++) {
        input5 >> words[i];
    }

    theSorter.introSort(words, words, words + 999);
    cout << "Intro Sort" << endl;

    for (int i = 0; i < 1000; i++) {
        cout << words[i] << " ";
    }
    cout << endl;
    input5.close();

    ifstream input6("../DatasetGeneration/string_datasets/randomized_no_duplicates_1000.txt", ios::in);

    for (int i = 0; i < 1000; i++) {
        input6 >> words[i];
    }

    theSorter.timSort(words, 1000);
    cout << "Tim Sort" << endl;

    for (int i = 0; i < 1000; i++) {
        cout << words[i] << " ";
    }
    cout << endl;
    input6.close();


//    int tester1[1000];
//    int tester2[1000];
//    int tester3[1000];
//    int tester4[1000];
//    int tester5[1000];
//    int tester6[1000];
//
//    cout << "Unsorted" << endl;
//    for (int i = 0; i < 1000; i++) {
//        int randomNum = rand() % 1000;
//        tester1[i] = randomNum;
//        tester2[i] = randomNum;
//        tester3[i] = randomNum;
//        tester4[i] = randomNum;
//        tester5[i] = randomNum;
//        tester6[i] = randomNum;
//
//        cout << randomNum << " ";
//    }
//    cout << endl;
//
//    theSorter.insertionSort(tester1, 0, 999);
//    cout << "Insertion Sort" << endl;
//
//    for (int i = 0; i < 1000; i++) {
//        cout << tester1[i] << " ";
//    }
//    cout << endl;
//
//    theSorter.randomizedQuickSort(tester2, 0, 999);
//    cout << "Quick Sort" << endl;
//
//    for (int i = 0; i < 1000; i++) {
//        cout << tester2[i] << " ";
//    }
//    cout << endl;
//
//    theSorter.mergeSort(tester3, 0, 999);
//    cout << "Merge Sort" << endl;
//
//    for (int i = 0; i < 1000; i++) {
//        cout << tester3[i] << " ";
//    }
//    cout << endl;
//
//    theSorter.shellSort(tester4, 1000);
//    cout << "Shell Sort" << endl;
//
//    for (int i = 0; i < 1000; i++) {
//        cout << tester4[i] << " ";
//    }
//    cout << endl;
//
//    theSorter.introSort(tester5, tester5, tester5 + 999);
//    cout << "Intro Sort" << endl;
//
//    for (int i = 0; i < 1000; i++) {
//        cout << tester5[i] << " ";
//    }
//    cout << endl;
//
//    theSorter.timSort(tester6, 1000);
//    cout << "Tim Sort" << endl;
//
//    for (int i = 0; i < 1000; i++) {
//        cout << tester6[i] << " ";
//    }
//    cout << endl;

}