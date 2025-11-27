EJ3 = ej3_vector
EXEC = ej1_vocales ej2_polinomio $(EJ3)

all: $(EXEC)

$(EJ3): $(EJ3).cc $(EJ3)es.cc
	g++ -o $@ $^

.PHONY: all clean

clean:
	rm -f *.o $(EXEC) producto.txt
