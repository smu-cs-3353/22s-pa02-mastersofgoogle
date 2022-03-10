cmake_minimum_required(VERSION 3.16)
project(22s_pa02_mastersofgoogle)

set (intput01 "../DatasetGeneration/int_datasets/randomized_no_duplicates_1000.txt")
set (intput02 "../DatasetGeneration/int_datasets/randomized_no_duplicates_5000.txt")
set (intput03 "../DatasetGeneration/int_datasets/randomized_no_duplicates_10000.txt")
set (intput04 "../DatasetGeneration/int_datasets/randomized_no_duplicates_25000.txt")
set (intput05 "../DatasetGeneration/int_datasets/randomized_no_duplicates_50000.txt")
set (intput06 "../DatasetGeneration/int_datasets/randomized_no_duplicates_100000.txt")

set (intput07 "../DatasetGeneration/int_datasets/sorted_no_duplicates_1000.txt")
set (intput08 "../DatasetGeneration/int_datasets/sorted_no_duplicates_5000.txt")
set (intput09 "../DatasetGeneration/int_datasets/sorted_no_duplicates_10000.txt")
set (intput10 "../DatasetGeneration/int_datasets/sorted_no_duplicates_25000.txt")
set (intput11 "../DatasetGeneration/int_datasets/sorted_no_duplicates_50000.txt")
set (intput12 "../DatasetGeneration/int_datasets/sorted_no_duplicates_100000.txt")

set (intput13 "../DatasetGeneration/int_datasets/60%_sorted_no_duplicates_1000.txt")
set (intput14 "../DatasetGeneration/int_datasets/60%_sorted_no_duplicates_5000.txt")
set (intput15 "../DatasetGeneration/int_datasets/60%_sorted_no_duplicates_10000.txt")
set (intput16 "../DatasetGeneration/int_datasets/60%_sorted_no_duplicates_25000.txt")
set (intput17 "../DatasetGeneration/int_datasets/60%_sorted_no_duplicates_50000.txt")
set (intput18 "../DatasetGeneration/int_datasets/60%_sorted_no_duplicates_100000.txt")

set (intput19 "../DatasetGeneration/int_datasets/randomized_20%_duplicates_1000.txt")
set (intput20 "../DatasetGeneration/int_datasets/randomized_20%_duplicates_5000.txt")
set (intput21 "../DatasetGeneration/int_datasets/randomized_20%_duplicates_10000.txt")
set (intput22 "../DatasetGeneration/int_datasets/randomized_20%_duplicates_25000.txt")
set (intput23 "../DatasetGeneration/int_datasets/randomized_20%_duplicates_50000.txt")
set (intput24 "../DatasetGeneration/int_datasets/randomized_20%_duplicates_100000.txt")

set (intput25 "../DatasetGeneration/int_datasets/randomized_40%_duplicates_1000.txt")
set (intput26 "../DatasetGeneration/int_datasets/randomized_40%_duplicates_5000.txt")
set (intput27 "../DatasetGeneration/int_datasets/randomized_40%_duplicates_10000.txt")
set (intput28 "../DatasetGeneration/int_datasets/randomized_40%_duplicates_25000.txt")
set (intput29 "../DatasetGeneration/int_datasets/randomized_40%_duplicates_50000.txt")
set (intput30 "../DatasetGeneration/int_datasets/randomized_40%_duplicates_100000.txt")

set (intput31 "../DatasetGeneration/string_datasets/randomized_no_duplicates_1000.txt")
set (intput32 "../DatasetGeneration/string_datasets/randomized_no_duplicates_5000.txt")
set (intput33 "../DatasetGeneration/string_datasets/randomized_no_duplicates_10000.txt")
set (intput34 "../DatasetGeneration/string_datasets/randomized_no_duplicates_25000.txt")
set (intput35 "../DatasetGeneration/string_datasets/randomized_no_duplicates_50000.txt")
set (intput36 "../DatasetGeneration/string_datasets/randomized_no_duplicates_100000.txt")

set (intput37 "../DatasetGeneration/string_datasets/sorted_no_duplicates_1000.txt")
set (intput38 "../DatasetGeneration/string_datasets/sorted_no_duplicates_5000.txt")
set (intput39 "../DatasetGeneration/string_datasets/sorted_no_duplicates_10000.txt")
set (intput40 "../DatasetGeneration/string_datasets/sorted_no_duplicates_25000.txt")
set (intput41 "../DatasetGeneration/string_datasets/sorted_no_duplicates_50000.txt")
set (intput42 "../DatasetGeneration/string_datasets/sorted_no_duplicates_100000.txt")

set (intput43 "../DatasetGeneration/string_datasets/60%_sorted_no_duplicates_1000.txt")
set (intput44 "../DatasetGeneration/string_datasets/60%_sorted_no_duplicates_5000.txt")
set (intput45 "../DatasetGeneration/string_datasets/60%_sorted_no_duplicates_10000.txt")
set (intput46 "../DatasetGeneration/string_datasets/60%_sorted_no_duplicates_25000.txt")
set (intput47 "../DatasetGeneration/string_datasets/60%_sorted_no_duplicates_50000.txt")
set (intput48 "../DatasetGeneration/string_datasets/60%_sorted_no_duplicates_100000.txt")

set (intput49 "../DatasetGeneration/string_datasets/randomized_20%_duplicates_1000.txt")
set (intput50 "../DatasetGeneration/string_datasets/randomized_20%_duplicates_5000.txt")
set (intput51 "../DatasetGeneration/string_datasets/randomized_20%_duplicates_10000.txt")
set (intput52 "../DatasetGeneration/string_datasets/randomized_20%_duplicates_25000.txt")
set (intput53 "../DatasetGeneration/string_datasets/randomized_20%_duplicates_50000.txt")
set (intput54 "../DatasetGeneration/string_datasets/randomized_20%_duplicates_100000.txt")

set (intput55 "../DatasetGeneration/string_datasets/randomized_40%_duplicates_1000.txt")
set (intput56 "../DatasetGeneration/string_datasets/randomized_40%_duplicates_5000.txt")
set (intput57 "../DatasetGeneration/string_datasets/randomized_40%_duplicates_10000.txt")
set (intput58 "../DatasetGeneration/string_datasets/randomized_40%_duplicates_25000.txt")
set (intput59 "../DatasetGeneration/string_datasets/randomized_40%_duplicates_50000.txt")
set (intput60 "../DatasetGeneration/string_datasets/randomized_40%_duplicates_100000.txt")

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
        src/main.cpp src/SortingAlgorithms.h)
