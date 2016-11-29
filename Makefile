obj_dir=/obj/
bin_dir=/bin/
src_dir=/src/
CC=gcc
CFLAGS=-c -Wall
SOURCES=$(src_dir)*.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=$(bin_dir)cobal.exe

all: $(SOURCES) $(EXECUTABLE)
    
cobal: $(OBJECTS) 
    $(CC) $(LDFLAGS) $(OBJECTS) -o $@

clean:
    rm -f $(OBJECTS) $(EXECUTABLE)