# PA 02: Sorting
by Michael Doherty

## Project Description
In this project, I needed to verify the upper bounds of the following six sorting algorithms:
- insertion sort
- randomized quicksort
- merge sort
- shellsort
- introsort
- timsort

Additionally, I needed to compare the performance of the sorting algorithms in the same Big-O class.
To do this, I needed to construct integer-based and string-based datasets. The following types of datasets were created:
- A randomized dataset with 0% duplicates
- A dataset with 0% duplicates sorted in ascending order
- A dataset with 0% duplicates with 60% of the dataset already sorted
- A randomized dataset with 20% duplicates
- A randomized dataset with 40% duplicates

Each type of dataset was created at six different sizes for both strings and integers (so a total of 60 datasets were created). The dataset sizes I chose were 1000, 5000, 10000, 25000, 50000, and 100000 elements.  

After generating the datasets and implementing the sorting algorithms, I needed to run each dataset through each of the six sorting algorithms and collect timing data using std::chrono. This data was then outputted to a csv file for data analysis.

## Building and Executing
To generate the datasets from the terminal, simply navigate to the DatasetGeneration folder and use the command:  
**python3 main.py**  

To build the sorting algorithms code from the terminal, simply navigate to the src folder and use the command:  
**g++ main.cpp SortingAlgorithms.h -o output**

(Note that after the -o, you can name the executable whatever you want). To run the sorting algorithms, simply type the command:  
**./output**  
(Again, note that output should be replaced with the name of your executable). No command line arguments are required for this program, as all file paths are already included in the source code.

## Report Questions
1) How did you generate the various data sets?
      - I generated the various data sets in Python. 
      - For the integer data sets, if there were no duplicates, then I simply iterated through a for loop the size of the data set, adding 0 - size - 1 to the data set. If any part of the data set needed to be randomized, then I used another for loop the size of the data set to generate random indices in the approriate range and swap the values at those indices. If any part of the array had duplicates, then I would use two for loops, both starting from i = 0, to generate the data (1 the size of the percent of the data set that needed to be duplicated, the other the remaining values needed for the data set).
      - For the string data sets, I generated 4 character strings that only had lowercase letters. I incremented each string by one letter as needed to form new strings, resetting the letters after they reached 'z' (Ex: 'aaaa' incremented to 'aaab', and 'aazz' incremented to 'abaa'). Like above, if any part of the data set needed to be randomized, then I used a for loop to generate random indices in the appropriate range and swap the values at those indices. If values needed to be repeated, then I would call my function that generated strings twice, once with size being the percent of values that needed to be duplicated, and once with the remaining size needed to be generated to complete the data set. Both function calls would start from 'aaaa'. (Ex: If 20% of values in a size 100 data set needed to be duplicated, then I would first generate 20 values starting from 'aaaa', then generate 80 more values starting from 'aaaa').
2) How does the performance of the various sorting algorithms differ between randomized data and pre-sorted data? Does this change with integers vs strings?
      - All of the sorting algorithms performed better when more of the data was sorted, regarless of the data type. The sorting algorithms were fastest on the datasets that were already sorted, followed by the datasets that were 60% sorted, followed by the completely randomized datasets. 
3) How do the algorithms perform as the datasets grow very large?
      - Out of all the algorithm's, only Insertion Sort's time increases dramatically as the dataset sizes grow larger (every dataset other than Insertion Sort consistenly performed in less than .1 seconds, while Insertion Sort's longest runtime was about 31 seconds for the randomized datasets of size 100000). Overall, this matches the Big-O of each algorithm, as Insertion Sort's is on average O(n<sup>2</sup>), while the other 5 sorting algorithms are on average O(n lg(n)). Nevertheless, each algorithm's runtime increases as size increases (as one would expect).
4) Does the performance of the sorting algorithms match published upper bounds?
      -
5) How does the performance of the algorithms change as duplicates are introduced?
      -
6) How does the performance of the algorithms change when the input is mostly sorted?
      -
7) Which algorithm is the best?
      -
