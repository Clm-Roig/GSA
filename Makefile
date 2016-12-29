obj_dir=obj/
bin_dir=bin/
src_dir=src/
CC=gcc
CFLAGS=-Wall
SOURCES=$(src_dir)*.c
OBJECTS=$(obj_dir)*.o
LDFLAGS=`sdl2-config --cflags --libs`
EXECUTABLE=$(bin_dir)cobal.exe

all: cobal

sdl: 
	$(CC) $(CFLAGS) $(src_dir)/sdl.c -o $(bin_dir)sdl $(LDFLAGS)

cobal: $(OBJECTS) 
	$(CC) -o $(EXECUTABLE) $(OBJECTS) $(LDFLAGS)

$(OBJECTS): $(SOURCES)
	$(CC) $(SOURCES) -o $(OBJECTS) $(LDFLAGS)

clean:
	rm -f $(OBJECTS) $(EXECUTABLE) $(bin_dir)/*
