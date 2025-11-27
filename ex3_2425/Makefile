EJ3 = ej3_matriz
EXEC = ej1_factores ej2_ordenar $(EJ3)

all: $(EXEC)

$(EJ3): $(EJ3).cc ej3_matrices.cc
	g++ -o $@ $^

.PHONY: all clean

clean:
	rm -f *.o $(EXEC) producto.txt
