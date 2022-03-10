//
// Created by mikec_g1kgiu8 on 3/2/2022.
//
#include <iostream>
#include "SortingAlgorithms.h"

using namespace std;

int main() {
    cout << "Now sorting ints" << endl;
    SortingAlgorithms<int> theIntSorter;

    //Sorts the int datasets that are randomized and have no duplicates
    cout << "randomized with no duplicates" << endl;
    theIntSorter.sortDatasets("../DatasetGeneration/int_datasets/randomized_no_duplicates");

    //Sorts the int datasets that are sorted and have no duplicates
    cout << "sorted with no duplicates" << endl;
    theIntSorter.sortDatasets("../DatasetGeneration/int_datasets/sorted_no_duplicates");

    //Sorts the int datasets that are 60% sorted and have no duplicates
    cout << "60% sorted with no duplicates" << endl;
    theIntSorter.sortDatasets("../DatasetGeneration/int_datasets/60%_sorted_no_duplicates");

    //Sorts the int datasets that are randomized and have 20% duplicates
    cout << "randomized with 20% duplicates" << endl;
    theIntSorter.sortDatasets("../DatasetGeneration/int_datasets/randomized_20%_duplicates");

    //Sorts the int datasets that are randomized and have 40% duplicates
    cout << "randomized with 40% duplicates" << endl;
    theIntSorter.sortDatasets("../DatasetGeneration/int_datasets/randomized_40%_duplicates");

    cout << "Now sorting strings" << endl;
    SortingAlgorithms<string> theStringSorter;

    //Sorts the string datasets that are randomized and have no duplicates
    cout << "randomized with no duplicates" << endl;
    theStringSorter.sortDatasets("../DatasetGeneration/string_datasets/randomized_no_duplicates");

    //Sorts the string datasets that are sorted and have no duplicates
    cout << "sorted with no duplicates" << endl;
    theStringSorter.sortDatasets("../DatasetGeneration/string_datasets/sorted_no_duplicates");

    //Sorts the string datasets that are 60% sorted and have no duplicates
    cout << "60% sorted with no duplicates" << endl;
    theStringSorter.sortDatasets("../DatasetGeneration/string_datasets/60%_sorted_no_duplicates");

    //Sorts the string datasets that are randomized and have 20% duplicates
    cout << "randomized with 20% duplicates" << endl;
    theStringSorter.sortDatasets("../DatasetGeneration/string_datasets/randomized_20%_duplicates");

    //Sorts the string datasets that are randomized and have 40% duplicates
    cout << "randomized with 40% duplicates" << endl;
    theStringSorter.sortDatasets("../DatasetGeneration/string_datasets/randomized_40%_duplicates");

    return 0;
}