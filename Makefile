
uptime.exe: main.cpp Uptime.o
	g++ -o uptime.exe main.cpp Uptime.o
	strip uptime.exe

Uptime.o: Uptime.h Uptime.cpp
	g++ -c Uptime.cpp

clean:
	rm *.o
	rm uptime.exe
	