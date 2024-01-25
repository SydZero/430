CXX = g++
FLAGS = -std=c++17

FILE ?= "*"

run: $(FILE).cpp
	$(CXX) $(CXXFLAGS) $(FILE).cpp
	./a.out
	rm -f a.out

