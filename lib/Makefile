LIB_FILES = gph_util.c graph.c
OBJ_FILES = gph_util.o graph.o
CFLAGS = -Wall -g

all:
	gcc $(CFLAGS) -c $(LIB_FILES)            # Make object files
	gcc -shared -o graph.so $(OBJ_FILES) -lm # Make shared object file
	ar rcs libgph.a $(OBJ_FILES)             # Make .a static library file
	
clean: 
	rm -f *.o
	rm -f *.a
	rm -f *.so

