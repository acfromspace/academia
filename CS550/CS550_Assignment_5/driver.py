# @author       kingofthenorth
# @filename     driver.py
# @description  Assignment 5
# @class        CS 550
# @instructor   Roch
# @notes        N/A

from ml_lib.learning import (DataSet,
                             DecisionTreeLearner, NeuralNetLearner)
from std_cv import cross_validation
from random import shuffle
from copy import deepcopy
import time

def elapsed(earlier, later):
    """
    keeps track of time issues while going through the problem
    """
    return time.strftime('%H:%M:%S', time.gmtime(later - earlier))

def learn(dataset):
    """
    retrieve a dataset
    shuffle the example list
    run a 10 fold cross validation (std_cv.cross_validation)
    use both DecisionTreeLearner and NeuralNetLearner
    use default options for NeuralNetLearner
    """
    print(dataset + " is the dataset being learned...\n")

    info = DataSet(name=dataset)
    info.attributes_to_numbers()
    cross_validation(DecisionTreeLearner, info)
    cross_validation(NeuralNetLearner, info, 1) # default options


def main():
    print("============================= Machine Learning ============================")
    print("CS 550 Artificial Intelligence | Prof. Roch | Assignment 5 | kingofthenorth")
    print("============================= Creating game... ============================")
    demo_start = time.time() # timer for results
    learn('iris')
    print("Overall time taken to learn: {}".format(elapsed(demo_start, time.time())))


if __name__ == '__main__':
    main()