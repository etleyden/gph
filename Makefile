# During active development, this file should be the one you want to run every time
TEST_FILES = ./tests/playground.c
UNIT_TEST = ./tests/unit_test.c
LIB_PATH = ./lib

# Make everything and run the unit tests 
all: dev_build

# Make and run the active development tests in one command
.SILENT:
go:
	make build_dev -s
	./test

dev_build:
	cd lib && make
	gcc -Wall -o test $(TEST_FILES) $(LIB_PATH)/graph.so -I$(LIB_PATH)

unit_test:
	cd lib && make
	gcc -Wall -o unit_test $(UNIT_TEST) $(LIB_PATH)/graph.so -I$(LIB_PATH)
	./unit_test # TODO: write a script which executes and validates unit test (including memory leak check)

clean_logs:
	rm -f tests/logs/*.txt

clean:
	cd lib && make clean -s
	rm -f test
	rm -f unit_test
	
