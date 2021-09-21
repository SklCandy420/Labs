from csv import reader
from random import seed
from random import randrange
from math import sqrt
from math import exp
from math import pi


def mean(numbers):
    return sum(numbers) / float(len(numbers))


def standard_deviation(numbers):
    avg = mean(numbers)
    variance = sum([(x - avg) ** 2 for x in numbers]) / float(len(numbers) - 1 + 0.0001)
    return sqrt(variance)


def load_csv(filename):
    dataset = list()
    with open(filename, "r") as file:
        csv_reader = reader(file)
        for row in csv_reader:
            if not row:
                continue
            r2 = []
            for i in range(1, len(row)):
                r2.append(row[i].lower())
            dataset.append(r2)
    return dataset


def col_tointeger(dataset, column):
    class_values = [row[column] for row in dataset]
    unique = set(class_values)
    lookup = dict()
    for i, value in enumerate(unique):
        lookup[value] = i
    for row in dataset:
        row[column] = lookup[row[column]]
    return lookup


def class_sep(dataset):
    separated = dict()
    for i in range(len(dataset)):
        vector = dataset[i]
        class_value = vector[-1]
        if class_value not in separated:
            separated[class_value] = list()
        separated[class_value].append(vector)
    return separated


def dataset_summary(dataset):
    summaries = [
        (mean(column), standard_deviation(column), len(column))
        for column in zip(*dataset)
    ]
    del summaries[-1]
    return summaries


def class_summary(dataset):
    separated = class_sep(dataset)
    summaries = dict()
    for class_value, rows in separated.items():
        summaries[class_value] = dataset_summary(rows)
    return summaries


def probability(x, mean, standard_deviation):
    exponent = exp(-((x - mean) ** 2 / (2 * standard_deviation ** 2 + 0.0000001)))
    return (1 / (sqrt(2 * pi) * standard_deviation + 0.0000001)) * exponent


def class_probabilities(summaries, row):
    total_rows = sum([summaries[label][0][2] for label in summaries])
    probabilities = dict()
    for class_value, class_summaries in summaries.items():
        probabilities[class_value] = summaries[class_value][0][2] / float(total_rows)
        for i in range(len(class_summaries)):
            mean, standard_deviation, _ = class_summaries[i]
            probabilities[class_value] *= probability(row[i], mean, standard_deviation)
    return probabilities


def prediction(summaries, row):
    probabilities = class_probabilities(summaries, row)
    best_label, best_prob = None, -1
    for class_value, probability in probabilities.items():
        if best_label is None or probability > best_prob:
            best_prob = probability
            best_label = class_value
    return best_label


filename = "DataSet2.csv"
dataset = load_csv(filename)
for i in range(len(dataset[0])):
    print(col_tointeger(dataset, i))
n_folds = 15
summaries = class_summary(dataset)
print("prediction:")
print(prediction(summaries, [1, 0, 1, 0, 1]))
