# 6 dataset sizes: 1000, 5000, 10000, 25000, 50000, 100000
import random
import string

def generate_int_data_sets(sizes):
    for size in sizes:  # goes through every dataset size
        dataset = []
        for i in range(size):  # creates a dataset with 0% duplicates in ascending order
            dataset.append(i)

        filename = "int_datasets/sorted_no_duplicates_" + str(size) + ".txt"
        with open(filename, "w") as output:
            for value in dataset:
                output.write(str(value))
                output.write("\n")

        percentage = size * 3 / 5  # FIXME name??

        for i in range(size):  # creates a dataset with 0% duplicates and the first 60% of the numbers in ascending order
            index1 = random.randint(percentage + 1, size - 1)
            index2 = random.randint(percentage + 1, size - 1)
            temp = dataset[index1]
            dataset[index1] = dataset[index2]
            dataset[index2] = temp

        temp = dataset[int(percentage)]  # ensures that only the first 60% of elements are in order
        dataset[int(percentage)] = dataset[size - 1]
        dataset[size - 1] = temp

        filename = "int_datasets/60%_sorted_no_duplicates_" + str(size) + ".txt"
        with open(filename, "w") as output:
            for value in dataset:
                output.write(str(value))
                output.write("\n")

        for i in range(size):  # creates a dataset with 0% duplicates in random order
            index1 = random.randint(0, size - 1)
            index2 = random.randint(0, size - 1)
            temp = dataset[index1]
            dataset[index1] = dataset[index2]
            dataset[index2] = temp

        filename = "int_datasets/randomized_no_duplicates_" + str(size) + ".txt"
        with open(filename, "w") as output:
            for value in dataset:
                output.write(str(value))
                output.write("\n")

        #FIXME did I generate the following datasets correctly?

        dataset = []
        percentage = size / 5  # FIXME name??

        for i in range(int(percentage)):
            dataset.append(i)

        for i in range(size - int(percentage)):
            dataset.append(i)

        for i in range(size):  # creates a dataset with 20% duplicates in random order
            index1 = random.randint(0, size - 1)
            index2 = random.randint(0, size - 1)
            temp = dataset[index1]
            dataset[index1] = dataset[index2]
            dataset[index2] = temp


        filename = "int_datasets/randomized_20%_duplicates_" + str(size) + ".txt"
        with open(filename, "w") as output:
            for value in dataset:
                output.write(str(value))
                output.write("\n")

        dataset = []
        percentage = size * 2 / 5  # FIXME name??

        for i in range(int(percentage)):
            dataset.append(i)

        for i in range(size - int(percentage)):
            dataset.append(i)

        for i in range(size):  # creates a dataset with 40% duplicates in random order
            index1 = random.randint(0, size - 1)
            index2 = random.randint(0, size - 1)
            temp = dataset[index1]
            dataset[index1] = dataset[index2]
            dataset[index2] = temp

        filename = "int_datasets/randomized_40%_duplicates_" + str(size) + ".txt"
        with open(filename, "w") as output:
            for value in dataset:
                output.write(str(value))
                output.write("\n")


def generate_string_data_sets(sizes):
    for size in sizes:
        dataset = []
        curr_string = "aaaa"
        for i in range(size):
            dataset.append(curr_string)

            if ord(curr_string[1]) + 1 > 122 and ord(curr_string[2]) + 1 > 122 and ord(curr_string[3]) + 1 > 122:
                string_list = list(curr_string)
                string_list[0] = chr(ord(curr_string[0]) + 1)
                string_list[1] = 'a'
                string_list[2] = 'a'
                string_list[3] = 'a'

                curr_string = "".join(string_list)
                continue
            elif ord(curr_string[2]) + 1 > 122 and ord(curr_string[3]) + 1 > 122:
                string_list = list(curr_string)
                string_list[1] = chr(ord(curr_string[1]) + 1)
                string_list[2] = 'a'
                string_list[3] = 'a'

                curr_string = "".join(string_list)
                continue
            elif ord(curr_string[3]) + 1 > 122:
                string_list = list(curr_string)
                string_list[2] = chr(ord(curr_string[2]) + 1)
                string_list[3] = 'a'

                curr_string = "".join(string_list)
                continue

            string_list = list(curr_string)

            string_list[3] = chr(ord(curr_string[3]) + 1)

            curr_string = "".join(string_list)

        filename = "string_datasets/sorted_no_duplicates_" + str(size) + ".txt"
        with open(filename, "w") as output:
            for value in dataset:
                output.write(str(value))
                output.write("\n")


sizes = [1000, 5000, 10000, 25000, 50000, 100000]
generate_int_data_sets(sizes)
generate_string_data_sets(sizes)