CXX = g++
CXXFLAGS = -std=c++17 -Wall
EJERC1 = mcd
EJERC2 = compra
CLASES = articulo.cc compra.cc

all: $(EJERC1) $(EJERC2)

$(EJERC1): ej1_$(EJERC1).cc
	$(CXX) $(CXXFLAGS) -o $@ $^

$(EJERC2): ej2_$(EJERC2).cc $(CLASES)
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY: all clean

clean :
	rm -f *.o $(EJERC1) $(EJERC2) salida.txt