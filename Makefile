obj_dir=obj/
bin_dir=bin/
src_dir=src/
CC=gcc
CFLAGS=-Wall -lm -lSDL2_image
SOURCES=$(src_dir)*.c
OBJECTS=$(obj_dir)*.o
LDFLAGS=`sdl2-config --cflags --libs`
EXECUTABLE=$(bin_dir)coal.exe

all: coal

coal: $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $(EXECUTABLE)

$(OBJECTS): $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) -o $(OBJECTS)

doxygen:
	doxygen Doxyfile

clean:
	rm -f $(OBJECTS) $(EXECUTABLE) $(bin_dir)/*
