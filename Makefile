test-Grid: src/Grid.cpp tests/test_Grid.cpp
	g++ $^ -I include/ -o test-Grid.exe