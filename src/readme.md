Instruccions per a poder executar el codi:

1. Al terminal escriure make

2. Un cop realitzat el pas anterior, trobaràs 4 executables amb els noms de :mainResultsBinomial (execució del binomial graph), mainResultsGeometric (execució de l'estudi de geometricGraph, mainResultsMeshAresta (execució del mesh graph amb percolació d'arestes), mainResultsMeshVertex (execució del mesh graph amb percolació de verrexs))

3. (optatiu) En cas de voler netejar els fitxers creats, fer servir make clean.

Contingut important de la carpeta:

- Carpeta Complexity: podem trobar els scripts de python amb les dades obtingudes de les crides en C++ de cada graph. (components complexes)
- Carpeta Connectivity: podem trobar els scripts de python amb les dades obtingudes de les crides en C++ de cada graph. (components connexes)
- Graficos: els gràfics de les dades de python en format .png
- Makefile
- Graph.cpp i Graph.h: declaració i implementació de la classe Graph.
- binomial.cpp i binomial.hh: declaració i implementació de les funcions que generen els grafs.
- percolacion.hh i percolation.hh: declaració i implementació de les funcions de percolació sobre els grafs
- utilities.cpp i utilities.h: declaració i implementació d'algunes funcions fetes servir a l'execució del programa.