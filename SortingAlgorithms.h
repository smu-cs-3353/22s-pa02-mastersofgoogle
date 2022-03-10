//
// Created by mikec_g1kgiu8 on 3/3/2022.
//

#ifndef INC_22S_PA02_MASTERSOFGOOGLE_SORTINGALGORITHMS_H
#define INC_22S_PA02_MASTERSOFGOOGLE_SORTINGALGORITHMS_H

#include <random>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <fstream>

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

        void sortDatasets(const string&);

};

template <typename T>
void SortingAlgorithms<T>::sortDatasets(const string& filePath) {
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

    ofstream output;
    if (filePath.find("string") < filePath.length()) {
        string outputFile = filePath + "_string_output.csv";
        outputFile.erase(outputFile.begin(), outputFile.begin() + 37);
        output.open("../output/" + outputFile, ios::out);
        cout << outputFile << endl;
    } else {
        string outputFile = filePath + "_int_output.csv";
        outputFile.erase(outputFile.begin(), outputFile.begin() + 34);
        output.open("../output/" + outputFile, ios::out);
    }

    if (!output.is_open()) {
        cout << "Could not open output file" << endl;
        return;
    }

    for (int i = 0; i < 36; i++) {
        ifstream input;
        int size;
        if (i < 6) {
            if (i == 0) {
                cout << "Size 1000:" << endl;
                output << "Size 1000:" << endl;
            }
            string textFile = filePath + "_1000.txt";
            input.open(textFile, ios::in);
            size = 1000;
        } else if (i < 12) {
            if (i == 6) {
                cout << "Size 5000:" << endl;
                output << "Size 5000:" << endl;
            }
            string textFile = filePath + "_5000.txt";
            input.open(textFile, ios::in);
            size = 5000;
        } else if (i < 18) {
            if (i == 12) {
                cout << "Size 10000:" << endl;
                output << "Size 10000:" << endl;
            }
            string textFile = filePath + "_10000.txt";
            input.open(textFile, ios::in);
            size = 10000;
        } else if (i < 24) {
            if (i == 18) {
                cout << "Size 25000:" << endl;
                output << "Size 25000:" << endl;
            }
            string textFile = filePath + "_25000.txt";
            input.open(textFile, ios::in);
            size = 25000;
        } else if (i < 30) {
            if (i == 24) {
                cout << "Size 50000:" << endl;
                output << "Size 50000:" << endl;
            }
            string textFile = filePath + "_50000.txt";
            input.open(textFile, ios::in);
            size = 50000;
        } else {
            if (i == 30) {
                cout << "Size 100000" << endl;
                output << "Size 100000:" << endl;
            }
            string textFile = filePath + "_100000.txt";
            input.open(textFile, ios::in);
            size = 100000;
        }
        T words[size];

        if (!input.is_open()) {
            cout << "Could not open file: " << filePath << endl;
            return;
        }

        for (int j = 0; j < size; j++) {
            input >> words[j];
//            cout << words[j] << " ";
        }
//        cout << endl;

        if (i % 6 == 0) {
            start = std::chrono::high_resolution_clock::now();
            insertionSort(words, 0, size - 1);
            end = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> time_in_seconds = end - start;
            cout << fixed << "Insertion Sort Duration: " << time_in_seconds.count() << endl;
            output << fixed << "Insertion Sort Duration: ," << time_in_seconds.count() << endl;
        } else if (i % 6 == 1) {
            start = std::chrono::high_resolution_clock::now();
            randomizedQuickSort(words, 0, size - 1);
            end = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> time_in_seconds = end - start;
            cout << fixed << "Quick Sort Duration: " << time_in_seconds.count() << endl;
            output << fixed << "Quick Sort Duration: ," << time_in_seconds.count() << endl;
        } else if (i % 6 == 2) {
            start = std::chrono::high_resolution_clock::now();
            mergeSort(words, 0, size - 1);
            end = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> time_in_seconds = end - start;
            cout << fixed << "Merge Sort Duration: " << time_in_seconds.count() << endl;
            output << fixed << "Merge Sort Duration: ," << time_in_seconds.count() << endl;
        } else if (i % 6 == 3) {
            start = std::chrono::high_resolution_clock::now();
            shellSort(words, size);
            end = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> time_in_seconds = end - start;
            cout << fixed << "Shell Sort Duration: " << time_in_seconds.count() << endl;
            output << fixed << "Shell Sort Duration: ," << time_in_seconds.count() << endl;
        } else if (i % 6 == 4) {
            start = std::chrono::high_resolution_clock::now();
            introSort(words, words, words + size - 1);
            end = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> time_in_seconds = end - start;
            cout << fixed << "Intro Sort Duration: " << time_in_seconds.count() << endl;
            output << fixed << "Intro Sort Duration: ," << time_in_seconds.count() << endl;
        } else {
            start = std::chrono::high_resolution_clock::now();
            timSort(words, size);
            end = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> time_in_seconds = end - start;
            cout << fixed << "Tim Sort Duration: " << time_in_seconds.count() << endl;
            output << fixed << "Tim Sort Duration: ," << time_in_seconds.count() << endl;
            cout << endl;
            output << endl;
        }
        input.close();
    }
    output.close();

}

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
