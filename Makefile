all:
	reset; 
	g++ -I./src/includes/ ./src/*.cpp -o main && wait;
	./main