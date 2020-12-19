

output: main.o
	g++ main.o -o run_final

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o
	rm run_final
