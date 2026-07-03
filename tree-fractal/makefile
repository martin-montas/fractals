tree:
	gcc main.c -o tree $(shell pkg-config --cflags --libs raylib) -lm -lX11 -lXrandr -lXi -lXcursor -lXinerama -ldl -lpthread

clean:
	rm -rf tree *.o
