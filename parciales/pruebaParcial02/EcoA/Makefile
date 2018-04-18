all: procesarecos

OBJECTS=procesarecos.o eco.o

procesarecos: $(OBJECTS)
	g++ -o $@ $(OBJECTS)

procesarecos.o: procesarecos.cpp eco.h
	g++ -c $<

eco.o: eco.cpp eco.h
	g++ -c $<

clean:
	- rm -f *.o procesarecos
|
