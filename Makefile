obj_dir=obj/
bin_dir=bin/
src_dir=src/
CC=gcc
CFLAGS=-Wall
SOURCES=$(src_dir)*.c
OBJECTS=$(SOURCES:.c=.o)
LDFLAGS=`sdl2-config --cflags --libs`
EXECUTABLE=$(bin_dir)cobal.exe

all: $(SOURCES) $(EXECUTABLE)

sdl:
	$(CC) $(CFLAGS) $(src_dir)/sdl.c -o $(bin_dir)sdl $(LDFLAGS)
cobal: $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
