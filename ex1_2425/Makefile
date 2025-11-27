EJ3 = ej3_rey
EXEC = ej1_coincide ej2_coeficiente_binomial $(EJ3)

all: $(EXEC)

$(EJ3): $(EJ3).cc $(EJ3)es.cc
	g++ -o $@ $^

.PHONY: all clean

clean:
	rm -f *.o $(EXEC)
