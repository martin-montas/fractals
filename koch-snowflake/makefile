flakes:
	gcc main.c -o flakes $(shell pkg-config --cflags --libs raylib) -lm -lX11 -lXrandr -lXi -lXcursor -lXinerama -ldl -lpthread

clean:
	rm -rf flakes *.o
