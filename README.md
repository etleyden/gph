# gph

This is a C library intended to provide simple and straightforward utilities for utilizing graphs in various contexts.

### To Build

Running `make` in the top directory will build tests/playground.c
Running `make build_prod` in the top directory will build tests/unit_test.c
Running `make` in the lib directory will build the library both as `.so` and `.a`, so you can use it in your own projects.
As usual, `make clean` will get rid of anything built after you cloned the repo.

### TODO

* Write clear and concise documentation
* Expand unit tests (there are currently none, but coming soon).
* Library is nowhere near completed, so here are some ideas:
    - Implement basic graph algorithms (BFS is done)
    - Implement a way to visualize graphs
