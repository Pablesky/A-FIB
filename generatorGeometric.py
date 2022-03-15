import os
import random
import string

def main():
    for i in range(0, 10):
        nameFile = "geometric_graph_" + str(i) + "_10_nodes"
        probability = str(random.uniform(0, 1))
        os.system("./geometricGraphGenerator 10 " + probability + " " + nameFile)  
    
    for i in range(0, 10):
        nameFile = "geometric_graph_" + str(i) + "_100_nodes"
        probability = str(random.uniform(0, 1))
        os.system("./geometricGraphGenerator 100 " + probability + " " + nameFile)

    for i in range(0, 10):
        nameFile = "geometric_graph_" + str(i) + "_1000_nodes"
        probability = str(random.uniform(0, 1))
        os.system("./geometricGraphGenerator 1000 " + probability + " " + nameFile)

    for i in range(0, 2):
        nameFile = "geometric_graph_" + str(i) + "_10000_nodes"
        probability = str(random.uniform(0, 1))
        os.system("./geometricGraphGenerator 10000 " + probability + " " + nameFile)  
            


if __name__ == '__main__':
    main()