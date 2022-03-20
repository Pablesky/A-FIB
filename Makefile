all:
	g++ -c *.cpp
	g++ -o mainResultsBinomial mainResultsBinomial.o Graph.o percolation.o utilities.o binomial.o
	g++ -o mainResultsGeometric mainResultsGeometric.o Graph.o percolation.o utilities.o binomial.o
	g++ -o mainResultsMesh mainResultsMesh.o Graph.o percolation.o utilities.o binomial.o

clean:
	rm *.o  mainResultsBinomial mainResultsGeometric