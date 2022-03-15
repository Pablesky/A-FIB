import os
import random
import string

def main():
    for i in range(0, 10):
        nameFile = " binomial_graph_" + str(i) + "_10_nodes"
        probability = str(random.uniform(0, 1))
        os.system("./binomialGraphGenerator 10 " + probability + " " + nameFile)  
    
    for i in range(0, 10):
        nameFile = " binomial_graph_" + str(i) + "_100_nodes"
        probability = str(random.uniform(0, 1))
        os.system("./binomialGraphGenerator 100 " + probability + " " + nameFile)

    for i in range(0, 10):
        nameFile = " binomial_graph_" + str(i) + "_1000_nodes"
        probability = str(random.uniform(0, 1))
        os.system("./binomialGraphGenerator 1000 " + probability + " " + nameFile)

    for i in range(0, 2):
        nameFile = " binomial_graph_" + str(i) + "_10000_nodes"
        probability = str(random.uniform(0, 1))
        os.system("./binomialGraphGenerator 10000 " + probability + " " + nameFile)  
            


if __name__ == '__main__':
    main()