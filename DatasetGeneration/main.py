# 6 dataset sizes: 1000, 5000, 10000, 25000, 50000, 100000
import random

def generate_data_set(sizes):
    for size in sizes:  # goes through every dataset size
        dataset = []
        for i in range(size):  # creates a dataset with 0% duplicates in ascending order
            dataset.append(i)

        filename = "datasets/sorted_no_duplicates_" + str(size) + ".txt"
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

        filename = "datasets/60%_sorted_no_duplicates_" + str(size) + ".txt"
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

        filename = "datasets/randomized_no_duplicates_" + str(size) + ".txt"
        with open(filename, "w") as output:
            for value in dataset:
                output.write(str(value))
                output.write("\n")



sizes = [1000, 5000, 10000, 25000, 50000, 100000]
generate_data_set(sizes)