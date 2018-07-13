Run : Run.o Propagator.o RFRay.o Ice.o Emitter.o Receiver.o Reflector.o
	g++ -o Run Run.o Propagator.o RFRay.o Ice.o Emitter.o Receiver.o Reflector.o

Receiver.o : Polarization.h
	g++ -c Receiver.cc

Propagator.o : Reflector.o RFRay.o Emitter.h Ice.h
	g++ -c Propagator.cc

Reflector.o : Reflector.h
	g++ -c Reflector.cc

RFRay.o : Emitter.o Ice.o Emitter.h Ice.h
	g++ -c RFRay.cc

Emitter.o : Emitter.h Polarization.h
	g++ -c Emitter.cc

Ice.o : Ice.h
	g++ -c Ice.cc

clean :
	rm Run.o Receiver.o Propagator.o Reflector.o RFRay.o Emitter.o Ice.o Run