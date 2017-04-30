all:
	g++ langtonMain.cpp Matrix.cpp Matrix.hpp Ant.cpp Ant.hpp utils.hpp utils.cpp -o main
	
clean:
	rm *o main