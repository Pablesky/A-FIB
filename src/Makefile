all:
	g++ -c *.cpp
	g++ -o mainResultsBinomial mainResultsBinomial.o Graph.o percolation.o utilities.o binomial.o
	g++ -o mainResultsGeometric mainResultsGeometric.o Graph.o percolation.o utilities.o binomial.o
	g++ -o mainResultsMeshAresta mainResultsMeshAresta.o Graph.o percolation.o utilities.o binomial.o
	g++ -o mainResultsMeshVertex mainResultsMeshVertex.o Graph.o percolation.o utilities.o binomial.o

clean:
	rm *.o  mainResultsBinomial mainResultsGeometric mainResultsMeshVertex mainResultsMeshAresta