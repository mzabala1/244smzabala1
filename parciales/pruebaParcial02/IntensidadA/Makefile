all: intensidadA

OBJECTS=intensidadA.o iluminanciaA.o

intensidadA: $(OBJECTS)
	g++ -o $@ $(OBJECTS)

intesidadA.o: intensidadA.cpp iluminanciaA.h
	g++ -c $<

iluminanciaA.o: iluminanciaA.cpp iluminanciaA.h
	g++ -c $<

clean:
	- rm -f *.o intensidadA
