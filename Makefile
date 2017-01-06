obj_dir=obj/
bin_dir=bin/
src_dir=src/
CC=gcc
CFLAGS=-Wall -lm -lSDL2_image -lSDL2
LDFLAGS=`sdl2-config --cflags --libs`
EXEC=coal

all: $(EXEC)

coal: $(obj_dir)BDD.o $(obj_dir)Camera.o $(obj_dir)Couleur.o $(obj_dir)ImageBMP.o $(obj_dir)Interface.o $(obj_dir)ReconnaissanceV.o $(obj_dir)Sdl_fenetres.o $(obj_dir)Sdl_init.o $(obj_dir)Sdl_main.o
	$(CC) $(LDFLAGS) -o $@ $^ 

$(obj_dir)%.o: $(src_dir)%.c
	$(CC) $(CFLAGS) -o $@ -c $<

doxygen:
	doxygen Doxyfile

clean:
	rm -f $(OBJECTS) $(EXECUTABLE) $(bin_dir)/*
