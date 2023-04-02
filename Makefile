# During active development, this file should be the one you want to run every time
TEST_FILES = ./tests/playground.c
UNIT_TEST = ./tests/unit_test.c
LIB_PATH = ./lib

# Make everything and run the unit tests 
all: build_dev

# Make and run the active development tests in one command
.SILENT:
go:
	make build_dev -s
	./test

build_dev:
	cd lib && make
	gcc -Wall -o test $(TEST_FILES) $(LIB_PATH)/graph.so -I$(LIB_PATH)

build_prod:
	cd lib && make
	gcc -Wall -o unit_test $(UNIT_TEST) $(LIB_PATH)/graph.so -I$(LIB_PATH)
	./unit_test


clean:
	cd lib && make clean -s
	rm -f test
	rm -f unit_test
	
