binomial:
	g++ -c *.cpp
	g++ -o binomialGraphGenerator generatorBinomialGraph.o binomial.o Graph.o percolation.o utilities.o 

geometric:
	g++ -c *.cpp
	g++ -o geometricGraphGenerator generatorBinomialGraph.o binomial.o Graph.o percolation.o utilities.o  

clean:
	rm *.o geometricGraphGenerator binomialGraphGenerator