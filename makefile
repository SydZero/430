CXX = g++
FLAGS = -std=c++17

FILE ?= "*"

run: $(FILE).cpp
	rm -f out.txt
	$(CXX) $(CXXFLAGS) $(FILE).cpp
	./a.out >> out.txt
	rm -f a.out

