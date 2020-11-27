CC=gcc
CFLAGS=-Wall -g
LFLAGS=-lgl2d -lglfw -lXrandr -lX11 -lGL -lGLU -lpthread -lm
INCDIR=-I.
LIBDIR=-L.
OBJS=game.o array.o box.o ball.o button.o

game: $(OBJS)
	$(CC) -o game $(OBJS) $(LIBDIR) $(LFLAGS)

game.o: game.c
	$(CC) -c game.c $(INCDIR) $(CFLAGS)

array.o: array.c array.h
	$(CC) -c array.c $(INCDIR) $(CFLAGS)

box.o: box.c box.h
	$(CC) -c box.c $(INCDIR) $(CFLAGS)

ball.o: ball.c ball.h
	$(CC) -c ball.c $(INCDIR) $(CFLAGS)

button.o: button.c button.h
	$(CC) -c button.c $(INCDIR) $(CFLAGS)

.PHONY: clean

clean:
	rm $(OBJS) game
