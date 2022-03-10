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
