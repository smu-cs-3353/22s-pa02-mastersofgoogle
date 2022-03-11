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

        //Recursive IntroSort function
        void introSort(T[], T*, T*, int);

        //HeapSort implementation for IntroSort
        void heapify(T[], int, int);
        void heapSort(T[], T*, T*);

        //Sorting Algorithms
        void insertionSort(T[], int, int);
        void randomizedQuickSort(T[], int, int);
        void mergeSort(T[], int, int);
        void shellSort(T[], int);
        void introSort(T[], T*, T*);
        void timSort(T[], int);

    public:
        //Function that calls all sorting algorithms on the provided path
        void sortDatasets(const string&);

};

template <typename T>
void SortingAlgorithms<T>::sortDatasets(const string& filePath) {
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end; //variables to count the time

    ofstream output;
    if (filePath.find("string") < filePath.length()) { //if filePath is for a string dataset
        string outputFile = filePath + "_string_output.csv"; //adds the output file ending
        outputFile.erase(outputFile.begin(), outputFile.begin() + 37); //removes ../DatasetGeneration/string_datasets/

        output.open("../output/" + outputFile, ios::out); //creates output file in output folder
    } else { //if filePath is for an int dataset
        string outputFile = filePath + "_int_output.csv"; //adds the output file ending
        outputFile.erase(outputFile.begin(), outputFile.begin() + 34); //removes ../DatasetGeneration/int_datasets/

        output.open("../output/" + outputFile, ios::out); //creates output file in output folder
    }

    if (!output.is_open()) { //if the output file does not open
        cout << "Could not open output file" << endl;
        return;
    }

    //the following loop iterates through each filePath dataset size and runs it through each sorting algorithm
    //Ex: If filePath is ../DatasetGeneration/int_datasets/randomized_no_duplicates, then it first runs
    // ../DatasetGeneration/int_datasets/randomized_no_duplicates_1000.txt through Insertion Sort, then
    // ../DatasetGeneration/int_datasets/randomized_no_duplicates through Quick Sort, etc.
    for (int i = 0; i < 36; i++) {
        ifstream input; //input file
        int size; //size of the dataset
        if (i < 6) { //size 1000 dataset for each of the 6 algorithms
            if (i == 0) { //for the first instance, print a header
                cout << "Size 1000:" << endl;
                output << "Size 1000:" << endl;
            }
            string textFile = filePath + "_1000.txt";
            input.open(textFile, ios::in); //opens the size 1000 dataset
            size = 1000;
        } else if (i < 12) { //size 5000 dataset for each of the 6 algorithms
            if (i == 6) { //for the first instance, print a header
                cout << "Size 5000:" << endl;
                output << "Size 5000:" << endl;
            }
            string textFile = filePath + "_5000.txt";
            input.open(textFile, ios::in); //opens the size 5000 dataset
            size = 5000;
        } else if (i < 18) { //size 10000 dataset for each of the 6 algorithms
            if (i == 12) { //for the first instance, print a header
                cout << "Size 10000:" << endl;
                output << "Size 10000:" << endl;
            }
            string textFile = filePath + "_10000.txt";
            input.open(textFile, ios::in); //opens the size 10000 dataset
            size = 10000;
        } else if (i < 24) { //size 25000 dataset for each of the 6 algorithms
            if (i == 18) { //for the first instance, print a header
                cout << "Size 25000:" << endl;
                output << "Size 25000:" << endl;
            }
            string textFile = filePath + "_25000.txt";
            input.open(textFile, ios::in); //opens the size 25000 dataset
            size = 25000;
        } else if (i < 30) { //size 50000 dataset for each of the 6 algorithms
            if (i == 24) { //for the first instance, print a header
                cout << "Size 50000:" << endl;
                output << "Size 50000:" << endl;
            }
            string textFile = filePath + "_50000.txt";
            input.open(textFile, ios::in); //opens the size 50000 dataset
            size = 50000;
        } else { //size 100000 dataset for each of the 6 algorithms
            if (i == 30) { //for the first instance, print a header
                cout << "Size 100000" << endl;
                output << "Size 100000:" << endl;
            }
            string textFile = filePath + "_100000.txt";
            input.open(textFile, ios::in); //opens the size 100000 dataset
            size = 100000;
        }
        T words[size]; //creates the array of the correct size

        if (!input.is_open()) { //if the input file could not be opened
            cout << "Could not open file: " << filePath << endl;
            return;
        }

        for (int j = 0; j < size; j++) { //input the data
            input >> words[j];
        }

        if (i % 6 == 0) { //calls Insertion Sort first for each dataset
            start = std::chrono::high_resolution_clock::now();
            insertionSort(words, 0, size - 1); //Insertion Sort call
            end = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> time_in_seconds = end - start; //calculates the time it took for the algorithm to sort the dataset
            cout << fixed << "Insertion Sort Duration: " << time_in_seconds.count() << endl;
            output << fixed << "Insertion Sort Duration: ," << time_in_seconds.count() << endl; //adds the algorithm's time to the csv file

        } else if (i % 6 == 1) { //calls Quick Sort second for each dataset
            start = std::chrono::high_resolution_clock::now();
            randomizedQuickSort(words, 0, size - 1);
            end = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> time_in_seconds = end - start; //calculates the time it took for the algorithm to sort the dataset
            cout << fixed << "Quick Sort Duration: " << time_in_seconds.count() << endl;
            output << fixed << "Quick Sort Duration: ," << time_in_seconds.count() << endl; //adds the algorithm's time to the csv file

        } else if (i % 6 == 2) { //calls Merge Sort third for each dataset
            start = std::chrono::high_resolution_clock::now();
            mergeSort(words, 0, size - 1);
            end = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> time_in_seconds = end - start; //calculates the time it took for the algorithm to sort the dataset
            cout << fixed << "Merge Sort Duration: " << time_in_seconds.count() << endl;
            output << fixed << "Merge Sort Duration: ," << time_in_seconds.count() << endl; //adds the algorithm's time to the csv file

        } else if (i % 6 == 3) { //calls Shell Sort fourth for each dataset
            start = std::chrono::high_resolution_clock::now();
            shellSort(words, size);
            end = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> time_in_seconds = end - start; //calculates the time it took for the algorithm to sort the dataset
            cout << fixed << "Shell Sort Duration: " << time_in_seconds.count() << endl;
            output << fixed << "Shell Sort Duration: ," << time_in_seconds.count() << endl; //adds the algorithm's time to the csv file

        } else if (i % 6 == 4) { //calls Intro Sort fifth for each dataset
            start = std::chrono::high_resolution_clock::now();
            introSort(words, words, words + size - 1);
            end = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> time_in_seconds = end - start; //calculates the time it took for the algorithm to sort the dataset
            cout << fixed << "Intro Sort Duration: " << time_in_seconds.count() << endl;
            output << fixed << "Intro Sort Duration: ," << time_in_seconds.count() << endl; //adds the algorithm's time to the csv file

        } else { //calls Tim Sort sixth for each dataset
            start = std::chrono::high_resolution_clock::now();
            timSort(words, size);
            end = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> time_in_seconds = end - start; //calculates the time it took for the algorithm to sort the dataset
            cout << fixed << "Tim Sort Duration: " << time_in_seconds.count() << endl;
            output << fixed << "Tim Sort Duration: ," << time_in_seconds.count() << endl; //adds the algorithm's time to the csv file
            cout << endl;
            output << endl;
        }
        input.close(); //closes the input file
    }
    output.close(); //closes the output file

}

//Inspired by code found at: https://www.geeksforgeeks.org/insertion-sort/ and https://www.techiedelight.com/introsort-algorithm/
template <typename T>
void SortingAlgorithms<T>::insertionSort(T theArray[], int low, int high) {
    for (int i = low + 1; i <= high; i++) { //start from second element (as first element is already sorted)
        T key = theArray[i];
        int j = i - 1;

        while (j >= low && theArray[j] > key) { //find index where theArray[i] belongs
            theArray[j + 1] = theArray[j];
            j -= 1;
        }
        theArray[j + 1] = key; //insert theArray[i] where it belongs
    }
}

//Inspired by code found at: https://www.geeksforgeeks.org/quicksort-using-random-pivoting/
template <typename T>
void SortingAlgorithms<T>::randomizedQuickSort(T theArray[], int low, int high) {
    if (low < high) {
        int partitionIndex = partition(theArray, low, high); //finds the point to partition around

        randomizedQuickSort(theArray, low, partitionIndex - 1); //sort elements before partition
        randomizedQuickSort(theArray, partitionIndex + 1, high); //sort elements after partition
    }
}

template <typename T>
int SortingAlgorithms<T>::partition(T theArray[], int low, int high) {
    int randomNum = (rand() % (high - low)) + low; //generates a random index

    swap(&theArray[randomNum], &theArray[high]); //swaps the value of the last element with the value of the random index's element

    T pivot = theArray[high]; //pivot is now the random index's element (which was moved to theArray[high])
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (theArray[j] <= pivot) { //if current element is less than or equal to the pivot
            i++;
            swap(&theArray[i], &theArray[j]); //swap the elements
        }
    }

    swap(&theArray[i + 1], &theArray[high]);
    return i + 1;
}

template <typename T>
void SortingAlgorithms<T>::swap(T* a, T* b) { //swaps the two values passed to it
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

    int middle = left + (right - left) / 2; //middle of the array

    mergeSort(theArray, left, middle); //the left half of the array
    mergeSort(theArray, middle + 1, right); //the right half of the array

    merge(theArray, left, middle, right); //recombines sorted halves

}

template <typename T>
void SortingAlgorithms<T>::merge(T theArray[], int left, int middle, int right) {
    int subArray1 = middle - left + 1;
    int subArray2 = right - middle;

    T* leftArray = new T[subArray1]; //temporary arrays
    T* rightArray = new T[subArray2];

    for (int i = 0; i < subArray1; i++) { //copies data to temporary array
        leftArray[i] = theArray[left + i];
    }

    for (int i = 0; i < subArray2; i++) { //copies data to temporary array
        rightArray[i] = theArray[middle + i + 1];
    }

    int subIndex1 = 0; //index of first subarray (the left subarray)
    int subIndex2 = 0; //index of second subarray (the right subarray)

    int mergedIndex = left; //index of the merged array

    while (subIndex1 < subArray1 && subIndex2 < subArray2) { //adds elements to the merged array in ascending order
        if (leftArray[subIndex1] <= rightArray[subIndex2]) {
            theArray[mergedIndex] = leftArray[subIndex1];
            subIndex1++;
        } else {
            theArray[mergedIndex] = rightArray[subIndex2];
            subIndex2++;
        }
        mergedIndex++;
    }

    while (subIndex1 < subArray1) { //adds any leftover elements from the left array to the merged array
        theArray[mergedIndex] = leftArray[subIndex1];
        subIndex1++;
        mergedIndex++;
    }

    while (subIndex2 < subArray2) { //adds any leftover elements from the right array to the merged array
        theArray[mergedIndex] = rightArray[subIndex2];
        subIndex2++;
        mergedIndex++;
    }

    delete[] leftArray; //deletes the temporary arrays
    delete[] rightArray; //deletes the temporary arrays
}

//Inspired by pseudo-code found at: https://www.tutorialspoint.com/data_structures_algorithms/shell_sort_algorithm.htm
template <typename T>
void SortingAlgorithms<T>::shellSort(T theArray[], int size) {
    int interval = 1;

    while (interval < size / 3) { //calculates the interval
        interval = interval * 3 + 1;
    }

    while (interval > 0) {
        for (int i = interval; i < size; i++) {
            T value = theArray[i]; //value to be inserted
            int j = i;

            while (j >= interval && theArray[j - interval] > value) { //shifts elements right
                theArray[j] = theArray[j - interval];
                j = j - interval;
            }

            theArray[j] = value; //inserts the selected value
        }

        interval = (interval - 1) / 3; //decrements the interval
    }
}

//Inspired by code found at: https://www.techiedelight.com/introsort-algorithm/
template <typename T>
void SortingAlgorithms<T>::introSort(T theArray[], T* beginning, T* end) {
    int depthLimit = 2 * log(end - beginning); //calculates the maximum depth

    introSort(theArray, beginning, end, depthLimit); //calls the recursive introSort function
}

template <typename T>
void SortingAlgorithms<T>::introSort(T theArray[], T* beginning, T* end, int depthLimit) {
    int size = end - beginning; //size of the subarray

    if (size < 16) { //if size is small enough, use insertionSort to sort the subarray
        insertionSort(theArray, beginning - theArray, end - theArray);
        return;
    } else if (depthLimit == 0) { //if the depthLimit is reached, then sort the subarray with heapSort
        T copy[size + 1]; //temporary copy of the part of the array that needs to be sorted
        int j = 0;
        for (int i = beginning - theArray; i < end - theArray + 1; i++) {
            copy[j] = theArray[i]; //copies that part of the array that needs to be sorted
            j++;
        }

        heapSort(copy, beginning, end + 1); //call heapSort on the part of the array that needs to be sorted

        j = 0;
        for (int i = beginning - theArray; i < end - theArray + 1; i++) {
            theArray[i] = copy[j]; //copies the newly sorted part of the array back to the original array
            j++;
        }
        return;
    } else { //Sort the array using quickSort

        T* partitionIndex = theArray + partition(theArray, beginning - theArray, end - theArray); //find the partition

        introSort(theArray, beginning, partitionIndex - 1, depthLimit - 1); //sort elements before partition
        introSort(theArray, partitionIndex + 1, end, depthLimit - 1); //sort elements after partition

        return;
    }
}

//Inspired by code found at: https://www.geeksforgeeks.org/heap-sort/
template<typename T>
void SortingAlgorithms<T>::heapSort(T theArray[], T* beginning, T* end) {
    int size = end - beginning; //size of the array/subarray

    for (int i = size / 2 - 1; i >= 0; i--) { //builds the heap
        heapify(theArray, size, i);
    }

    for (int i = size - 1; i >= 0; i--) { //extracts elements from the heap
        swap(&theArray[0], &theArray[i]); //move root to the end
        heapify(theArray, i, 0); //heapify the newly reduced heap
    }
}

template<typename T>
void SortingAlgorithms<T>::heapify(T theArray[], int size, int i) {
    int largest = i; //largest is initially the root
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && theArray[left] > theArray[largest]) { //if left is larger than the root
        largest = left;
    }

    if (right < size && theArray[right] > theArray[largest]) { //if right is larger than the left and the root
        largest = right;
    }

    if (largest != i) { //if largest was changed to either left or right
        swap(&theArray[i], &theArray[largest]); //swap values
        heapify(theArray, size, largest); //heapify the subtree
    }
}

//Inspired by code found at: https://www.geeksforgeeks.org/timsort/
template <typename T>
void SortingAlgorithms<T>::timSort(T theArray[], int size) {
    int run = 32;
    for (int i = 0; i < size; i += run) { //sort subarrays (with each subarray having 32 elements) using insertion sort
        insertionSort(theArray, i, std::min((i + run - 1), (size - 1)));
    }

    for (int i = run; i < size; i *= 2) { //merge the subarrays (of increasingly larger sizes)
        for (int left = 0; left < size; left += i * 2) {
            int middle = left + i - 1; //endpoint of left subarray
            int right = std::min((left + 2 * i - 1), (size - 1)); //endpoint of right subarray

            if (middle < right) {
                merge(theArray, left, middle, right); //merge the subarrays
            }
        }
    }
}


#endif //INC_22S_PA02_MASTERSOFGOOGLE_SORTINGALGORITHMS_H
