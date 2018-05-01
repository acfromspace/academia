
from statistics import (stdev, mean)
from ml_lib.learning import (err_ratio, train_and_test)
import copy

def cross_validation(learner, dataset, k=10, trials=1):
    """Perform k-fold cross_validation
    Run k trials where each trial has a different (k-1)/k percentage
    of the data as training data and 1/k as test data.
    
    Returns tuple (mean_err, std_err, fold_errors, models)
    """
    training_module = copy.deepcopy(dataset)
    folds = []
    for counter in range(k):
        # gets the length of the dataset examples to be parsed through
        n = len(dataset.examples)
        solution = []
        correct = 0

        # create a whole data structure based off of the dataset
        info_samples = list(map(lambda x: x[:-1], dataset.examples))
        info_labels = list(map(lambda x: x[-1], dataset.examples))
        decision_tree = learner(training_module)

        # zip combines same attributes across data structures, think like a zipper
        for first, second in zip(info_samples, info_labels):
            if (decision_tree(first) == second):
                solution.append(1)
                correct += 1
            else:
                solution.append(0)

        folds.append(correct/n)
        training_module.examples += dataset.examples

    print("Data samples:", info_samples,"\nData labels:", info_labels,
          "\nMean:", mean(solution), "\nStandard Deviation:", stdev(solution, mean(solution)),
          "\nError rates for folds:", folds, "\nLearner Name:", learner.__name__,"\n")