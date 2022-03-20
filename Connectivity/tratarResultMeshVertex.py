from cProfile import label
import matplotlib.pyplot as plt

#Binomial Graphs
#Execucio de 100 grafs per a cada probabilitat
xAxis = [0,0.05,0.1,0.15,0.2,0.25,0.3,0.35,0.4,0.45,0.5,0.55,0.6,0.65,0.7,0.75,0.8,0.85,0.9,0.95]
grafo100 = [0,0.03,0,0,0,0,0,0,0,0,0,0.01,0,0.04,0.2,0.34,0.67,0.76,0.91,0.98]
grafo400 = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0.2,0.7,0.9,1]
grafo2500 = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0.1,0.5,1]
grafo3600 = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0.3,0.8,1]
grafo10000 = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0.2,0.9]
plt.plot(xAxis, grafo100, label = "10x10")
plt.plot(xAxis, grafo400, label = "20x20")
plt.plot(xAxis, grafo2500, label = "50x50")
plt.plot(xAxis, grafo3600, label = "60x60")
plt.plot(xAxis, grafo10000, label = "100x100")
plt.legend()
plt.title("Mesh Graph Generator Vertex Percolation")
plt.xlabel("Probability percolation")
plt.ylabel("Ratio connectivity")
plt.show()