all: deviceuse

OBJECTS=deviceuse.o device.o

deviceuse: $(OBJECTS)
	g++ -o $@ $(OBJECTS)

deviceuse.o: deviceuse.cpp device.h
	g++ -c $<

device.o: device.cpp device.h
	g++ -c $<

clean:
	- rm -f *.o deviceuse
