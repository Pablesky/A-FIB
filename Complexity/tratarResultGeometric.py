from cProfile import label
import matplotlib.pyplot as plt

#Binomial Graphs
#Execucio de 100 grafs per a cada probabilitat
xAxis = [0,0.05,0.1,0.15,0.2,0.25,0.3,0.35,0.4,0.45,0.5,0.55,0.6,0.65,0.7,0.75,0.8,0.85,0.9,0.95]
grafo20 = [1,1,0.91,0.51,0.12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
grafo60 = [1,0.85,0.01,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
grafo100 = [1,0.36,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
grafo1000 = [1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
grafo5000 = [1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
plt.plot(xAxis, grafo20, label = "20")
plt.plot(xAxis, grafo60, label = "60")
plt.plot(xAxis, grafo100, label = "100")
plt.plot(xAxis, grafo1000, label = "1000")
plt.plot(xAxis, grafo5000, label = "5000")
plt.legend()
plt.title("Geometric Graph Generator")
plt.xlabel("Radius geometric")
plt.ylabel("Ratio connectivity")
plt.show()