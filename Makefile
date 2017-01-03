obj_dir=obj/
bin_dir=bin/
src_dir=src/
CC=gcc
CFLAGS=-Wall
SOURCES=$(src_dir)*.c
OBJECTS=$(obj_dir)*.o
LDFLAGS=`sdl2-config --cflags --libs` -lm -lSDL2_image
EXECUTABLE=$(bin_dir)coal.exe

all: coal

coal: $(OBJECTS)
	$(CC) -o $(EXECUTABLE) $(OBJECTS) $(LDFLAGS)

$(OBJECTS): $(SOURCES)
	$(CC) $(SOURCES) -o $(OBJECTS) $(LDFLAGS)

doxygen:
	doxygen Doxyfile

clean:
	rm -f $(OBJECTS) $(EXECUTABLE) $(bin_dir)/*
