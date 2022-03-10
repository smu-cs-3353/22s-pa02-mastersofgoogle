# 6 dataset sizes: 1000, 5000, 10000, 25000, 50000, 100000
import random


def generate_int_data_sets(sizes):  # generates all of the int datasets
    for size in sizes:  # goes through every dataset size
        dataset = []
        for i in range(size):  # creates a dataset with 0% duplicates in ascending order
            dataset.append(i)

        filename = "int_datasets/sorted_no_duplicates_" + str(size) + ".txt"  # creates the filename
        with open(filename, "w") as output:  # writes the data to the output file
            for value in dataset:
                output.write(str(value))
                output.write("\n")

        percentage = size * 3 / 5  # 60% of the dataset

        for i in range(
                size):  # creates a dataset with 0% duplicates and the first 60% of the numbers in ascending order
            index1 = random.randint(percentage, size - 1)  # random index in the last 40% of the data
            index2 = random.randint(percentage, size - 1)  # random index in the last 40% of the data
            temp = dataset[index1]  # swaps the data
            dataset[index1] = dataset[index2]
            dataset[index2] = temp

        temp = dataset[int(percentage)]  # ensures that only the first 60% of elements are in order
        dataset[int(percentage)] = dataset[size - 1]
        dataset[size - 1] = temp

        filename = "int_datasets/60%_sorted_no_duplicates_" + str(size) + ".txt"  # creates the filename
        with open(filename, "w") as output:  # writes the data to the output file
            for value in dataset:
                output.write(str(value))
                output.write("\n")

        for i in range(size):  # creates a dataset with 0% duplicates in random order
            index1 = random.randint(0, size - 1)  # random index
            index2 = random.randint(0, size - 1)  # random index
            temp = dataset[index1]  # swaps the data
            dataset[index1] = dataset[index2]
            dataset[index2] = temp

        filename = "int_datasets/randomized_no_duplicates_" + str(size) + ".txt"  # creates the filename
        with open(filename, "w") as output:  # writes the data to the output file
            for value in dataset:
                output.write(str(value))
                output.write("\n")

        dataset = []
        percentage = size / 5  # 20% of the dataset

        for i in range(int(percentage)):  # creates the first 20% of the dataset (starting at i = 0)
            dataset.append(i)

        for i in range(size - int(percentage)):  # creates the next 80% of the dataset (starting at i = 0)
            dataset.append(i)

        for i in range(size):  # creates a dataset with 20% duplicates in random order
            index1 = random.randint(0, size - 1)  # random index
            index2 = random.randint(0, size - 1)  # random index
            temp = dataset[index1]  # swaps the data
            dataset[index1] = dataset[index2]
            dataset[index2] = temp

        filename = "int_datasets/randomized_20%_duplicates_" + str(size) + ".txt"  # creates the filename
        with open(filename, "w") as output:  # writes the data to the output file
            for value in dataset:
                output.write(str(value))
                output.write("\n")

        dataset = []
        percentage = size * 2 / 5  # 40% of the dataset

        for i in range(int(percentage)):  # creates the first 40% of the dataset (starting at i = 0)
            dataset.append(i)

        for i in range(size - int(percentage)):  # creates the next 60% of the dataset (starting at i = 0)
            dataset.append(i)

        for i in range(size):  # creates a dataset with 40% duplicates in random order
            index1 = random.randint(0, size - 1)  # random index
            index2 = random.randint(0, size - 1)  # random index
            temp = dataset[index1]  # swaps the data
            dataset[index1] = dataset[index2]
            dataset[index2] = temp

        filename = "int_datasets/randomized_40%_duplicates_" + str(size) + ".txt"  # creates the filename
        with open(filename, "w") as output:  # writes the data to the output file
            for value in dataset:
                output.write(str(value))
                output.write("\n")


def generate_strings(size):  # generates all the needed strings
    dataset = []
    curr_string = "aaaa"  # the first string
    for i in range(size):  # loop that generates all of the needed strings
        dataset.append(curr_string)

        if ord(curr_string[1]) + 1 > 122 and ord(curr_string[2]) + 1 > 122 and ord(
                curr_string[3]) + 1 > 122:  # if the second, third, and last characters are 'z' (Ex: 'azzz')
            string_list = list(curr_string)
            string_list[0] = chr(ord(curr_string[0]) + 1)  # Increments the first character
            string_list[1] = 'a'  # Resets the second letter
            string_list[2] = 'a'  # Resets the third letter
            string_list[3] = 'a'  # Resets the last letter (Ex: from 'azzz' to 'baaa)

            curr_string = "".join(string_list)
            continue
        elif ord(curr_string[2]) + 1 > 122 and ord(
                curr_string[3]) + 1 > 122:  # if the third and last characters are 'z' (Ex: 'aazz')
            string_list = list(curr_string)
            string_list[1] = chr(ord(curr_string[1]) + 1)  # Increments the second letter
            string_list[2] = 'a'  # Resets the third letter
            string_list[3] = 'a'  # Resets the last letter (Ex: from 'aazz' to 'abaa)

            curr_string = "".join(string_list)
            continue
        elif ord(curr_string[3]) + 1 > 122:  # if the last character is 'z' (Ex: 'aaaz')
            string_list = list(curr_string)
            string_list[2] = chr(ord(curr_string[2]) + 1)  # Increments the third letter
            string_list[3] = 'a'  # Resets the last letter (Ex: from 'aaaz' to 'aaba)

            curr_string = "".join(string_list)
            continue

        string_list = list(curr_string)

        string_list[3] = chr(ord(curr_string[3]) + 1)  # increments the last letter by one (Ex: from 'aaaa' to 'aaab')

        curr_string = "".join(string_list)

    return dataset  # Returns the generated list of strings


def generate_string_data_sets(sizes):  # generates all of the string datasets
    for size in sizes:  # goes through every dataset size
        dataset = generate_strings(size)  # generates the number of strings needed

        filename = "string_datasets/sorted_no_duplicates_" + str(size) + ".txt"  # creates the filename
        with open(filename, "w") as output:  # writes the data to the output file
            for value in dataset:
                output.write(str(value))
                output.write("\n")

        percentage = size * 3 / 5  # 60% of the dataset

        for i in range(
                size):  # creates a dataset with 0% duplicates and the first 60% of the numbers in ascending order
            index1 = random.randint(percentage, size - 1)  # random index in the last 40% of the data
            index2 = random.randint(percentage, size - 1)  # random index in the last 40% of the data
            temp = dataset[index1]  # swaps the data
            dataset[index1] = dataset[index2]
            dataset[index2] = temp

        temp = dataset[int(percentage)]  # ensures that only the first 60% of elements are in order
        dataset[int(percentage)] = dataset[size - 1]
        dataset[size - 1] = temp

        filename = "string_datasets/60%_sorted_no_duplicates_" + str(size) + ".txt"  # creates the filename
        with open(filename, "w") as output:  # writes the data to the output file
            for value in dataset:
                output.write(str(value))
                output.write("\n")

        for i in range(size):  # creates a dataset with 0% duplicates in random order
            index1 = random.randint(0, size - 1)  # random index
            index2 = random.randint(0, size - 1)  # random index
            temp = dataset[index1]  # swaps the data
            dataset[index1] = dataset[index2]
            dataset[index2] = temp

        filename = "string_datasets/randomized_no_duplicates_" + str(size) + ".txt"  # creates the filename
        with open(filename, "w") as output:  # writes the data to the output file
            for value in dataset:
                output.write(str(value))
                output.write("\n")

        dataset = []
        percentage = size / 5  # 20% of the dataset

        dataset = generate_strings(int(percentage))  # generates the first 20% of the data (starting from 'aaaa')
        dataset2 = generate_strings(size - int(percentage))  # generates the last 80% of the data (starting from 'aaaa')

        dataset.extend(dataset2)  # combines the two lists of strings

        for i in range(size):  # creates a dataset with 20% duplicates in random order
            index1 = random.randint(0, size - 1)  # random index
            index2 = random.randint(0, size - 1)  # random index
            temp = dataset[index1]  # swaps the data
            dataset[index1] = dataset[index2]
            dataset[index2] = temp

        filename = "string_datasets/randomized_20%_duplicates_" + str(size) + ".txt"  # creates the filename
        with open(filename, "w") as output:  # writes the data to the output file
            for value in dataset:
                output.write(str(value))
                output.write("\n")

        dataset = []
        percentage = size * 2 / 5  # 40% of the dataset

        dataset = generate_strings(int(percentage))  # generates the first 40% of the data (starting from 'aaaa')
        dataset2 = generate_strings(size - int(percentage))  # generates the last 60% of the data (starting from 'aaaa')

        dataset.extend(dataset2)  # combines the two lists of strings

        for i in range(size):  # creates a dataset with 40% duplicates in random order
            index1 = random.randint(0, size - 1)  # random index
            index2 = random.randint(0, size - 1)  # random index
            temp = dataset[index1]  # swaps the data
            dataset[index1] = dataset[index2]
            dataset[index2] = temp

        filename = "string_datasets/randomized_40%_duplicates_" + str(size) + ".txt"  # creates the filename
        with open(filename, "w") as output:  # writes the data to the output file
            for value in dataset:
                output.write(str(value))
                output.write("\n")


sizes = [1000, 5000, 10000, 25000, 50000, 100000]  # dataset sizes
generate_int_data_sets(sizes)  # generates the int datasets
generate_string_data_sets(sizes)  # generates the string datasets
