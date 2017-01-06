obj_dir=obj/
bin_dir=bin/
src_dir=src/
CC=gcc
CFLAGS=-Wall -lm -lSDL2_image -lSDL2
LDFLAGS=`sdl2-config --cflags --libs`
EXEC=$(bin_dir)coal.exe

all: $(EXEC)

hello: $(obj_dir)*.o
	$(CC) -o $@ $^ $(LDFLAGS)

$(obj_dir)%.o: $(src_dir)%.c
	$(CC) -o $@ -c $< $(CFLAGS)

doxygen:
	doxygen Doxyfile

clean:
  rm -f $(OBJECTS) $(EXECUTABLE) $(bin_dir)/*
