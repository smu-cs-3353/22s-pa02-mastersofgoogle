cmake_minimum_required(VERSION 3.16)
project(22s_pa02_mastersofgoogle)

set (input01 "DatasetGeneration/int_datasets/randomized_no_duplicates_1000.txt")
set (input02 "DatasetGeneration/int_datasets/randomized_no_duplicates_5000.txt")
set (input03 "DatasetGeneration/int_datasets/randomized_no_duplicates_10000.txt")
set (input04 "DatasetGeneration/int_datasets/randomized_no_duplicates_25000.txt")
set (input05 "DatasetGeneration/int_datasets/randomized_no_duplicates_50000.txt")
set (input06 "DatasetGeneration/int_datasets/randomized_no_duplicates_100000.txt")

set (input07 "DatasetGeneration/int_datasets/sorted_no_duplicates_1000.txt")
set (input08 "DatasetGeneration/int_datasets/sorted_no_duplicates_5000.txt")
set (input09 "DatasetGeneration/int_datasets/sorted_no_duplicates_10000.txt")
set (input10 "DatasetGeneration/int_datasets/sorted_no_duplicates_25000.txt")
set (input11 "DatasetGeneration/int_datasets/sorted_no_duplicates_50000.txt")
set (input12 "DatasetGeneration/int_datasets/sorted_no_duplicates_100000.txt")

set (input13 "DatasetGeneration/int_datasets/60%_sorted_no_duplicates_1000.txt")
set (input14 "DatasetGeneration/int_datasets/60%_sorted_no_duplicates_5000.txt")
set (input15 "DatasetGeneration/int_datasets/60%_sorted_no_duplicates_10000.txt")
set (input16 "DatasetGeneration/int_datasets/60%_sorted_no_duplicates_25000.txt")
set (input17 "DatasetGeneration/int_datasets/60%_sorted_no_duplicates_50000.txt")
set (input18 "DatasetGeneration/int_datasets/60%_sorted_no_duplicates_100000.txt")

set (input19 "DatasetGeneration/int_datasets/randomized_20%_duplicates_1000.txt")
set (input20 "DatasetGeneration/int_datasets/randomized_20%_duplicates_5000.txt")
set (input21 "DatasetGeneration/int_datasets/randomized_20%_duplicates_10000.txt")
set (input22 "DatasetGeneration/int_datasets/randomized_20%_duplicates_25000.txt")
set (input23 "DatasetGeneration/int_datasets/randomized_20%_duplicates_50000.txt")
set (input24 "DatasetGeneration/int_datasets/randomized_20%_duplicates_100000.txt")

set (input25 "DatasetGeneration/int_datasets/randomized_40%_duplicates_1000.txt")
set (input26 "DatasetGeneration/int_datasets/randomized_40%_duplicates_5000.txt")
set (input27 "DatasetGeneration/int_datasets/randomized_40%_duplicates_10000.txt")
set (input28 "DatasetGeneration/int_datasets/randomized_40%_duplicates_25000.txt")
set (input29 "DatasetGeneration/int_datasets/randomized_40%_duplicates_50000.txt")
set (input30 "DatasetGeneration/int_datasets/randomized_40%_duplicates_100000.txt")

set (input31 "DatasetGeneration/string_datasets/randomized_no_duplicates_1000.txt")
set (input32 "DatasetGeneration/string_datasets/randomized_no_duplicates_5000.txt")
set (input33 "DatasetGeneration/string_datasets/randomized_no_duplicates_10000.txt")
set (input34 "DatasetGeneration/string_datasets/randomized_no_duplicates_25000.txt")
set (input35 "DatasetGeneration/string_datasets/randomized_no_duplicates_50000.txt")
set (input36 "DatasetGeneration/string_datasets/randomized_no_duplicates_100000.txt")

set (input37 "DatasetGeneration/string_datasets/sorted_no_duplicates_1000.txt")
set (input38 "DatasetGeneration/string_datasets/sorted_no_duplicates_5000.txt")
set (input39 "DatasetGeneration/string_datasets/sorted_no_duplicates_10000.txt")
set (input40 "DatasetGeneration/string_datasets/sorted_no_duplicates_25000.txt")
set (input41 "DatasetGeneration/string_datasets/sorted_no_duplicates_50000.txt")
set (input42 "DatasetGeneration/string_datasets/sorted_no_duplicates_100000.txt")

set (input43 "DatasetGeneration/string_datasets/60%_sorted_no_duplicates_1000.txt")
set (input44 "DatasetGeneration/string_datasets/60%_sorted_no_duplicates_5000.txt")
set (input45 "DatasetGeneration/string_datasets/60%_sorted_no_duplicates_10000.txt")
set (input46 "DatasetGeneration/string_datasets/60%_sorted_no_duplicates_25000.txt")
set (input47 "DatasetGeneration/string_datasets/60%_sorted_no_duplicates_50000.txt")
set (input48 "DatasetGeneration/string_datasets/60%_sorted_no_duplicates_100000.txt")

set (input49 "DatasetGeneration/string_datasets/randomized_20%_duplicates_1000.txt")
set (input50 "DatasetGeneration/string_datasets/randomized_20%_duplicates_5000.txt")
set (input51 "DatasetGeneration/string_datasets/randomized_20%_duplicates_10000.txt")
set (input52 "DatasetGeneration/string_datasets/randomized_20%_duplicates_25000.txt")
set (input53 "DatasetGeneration/string_datasets/randomized_20%_duplicates_50000.txt")
set (input54 "DatasetGeneration/string_datasets/randomized_20%_duplicates_100000.txt")

set (input55 "DatasetGeneration/string_datasets/randomized_40%_duplicates_1000.txt")
set (input56 "DatasetGeneration/string_datasets/randomized_40%_duplicates_5000.txt")
set (input57 "DatasetGeneration/string_datasets/randomized_40%_duplicates_10000.txt")
set (input58 "DatasetGeneration/string_datasets/randomized_40%_duplicates_25000.txt")
set (input59 "DatasetGeneration/string_datasets/randomized_40%_duplicates_50000.txt")
set (input60 "DatasetGeneration/string_datasets/randomized_40%_duplicates_100000.txt")

foreach(file IN LISTS input01 input02 input03 input04 input05 input06 input07 input08 
        input09 input10 input11 input12 input13 input14 input15 input16 input17 input18
        input19 input20 input21 input22 input23 input24 input25 input26 input27 input28
        input29 input30 input31 input32 input33 input34 input35 input36 input37 input38
        input39 input40 input41 input42 input43 input44 input45 input46 input47 input48
        input49 input50 input51 input52 input53 input54 input55 input56 input57 input58
        input59 input60)
    configure_file(${file} ${file} COPYONLY)
endforeach()

set(CMAKE_CXX_STANDARD 14)

add_executable(22s_pa02_mastersofgoogle
        main.cpp SortingAlgorithms.h)
