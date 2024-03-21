CXX = g++
FLAGS = -std=c++17

FILE ?= "*"

run: $(FILE).cpp
	rm -f out.txt
	$(CXX) $(FLAGS) $(FILE).cpp
	./a.out < in.txt >> out.txt
	rm -f a.out

