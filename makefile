julia:
	gcc main.cpp -o julia -lSDL2

clean:
	rm -rf julia *.o
