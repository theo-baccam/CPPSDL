terminal: src/*.cpp
	g++ $^ -I include/ -o 2048-terminal.exe


test-Grid: src/Grid.cpp tests/test_Grid.cpp
	g++ $^ -I include/ -o test-Grid.exe