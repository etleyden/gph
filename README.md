# gph

This is a C library intended to provide simple and straightforward utilities for utilizing graphs in various contexts.

### To Build

Running `make` in the top directory will build tests/playground.c

`make unit_test` in the top directory will build tests/unit_test.c

`make` in the lib directory will build the library both as `.so` and `.a`, so you can use it in your own projects.

As usual, `make clean` will get rid of anything built after you cloned the repo.

`make clean_logs` will remove all .txt files in tests/logs


### TODO

* Write clear and concise documentation
* Keep unit tests up to date
* Library is nowhere near completed, so here are some ideas:
    - Implement basic graph algorithms (BFS is done)
    - Implement a way to visualize graphs
