# Specify the C++ compiler
CXX = g++

# Specify options to pass to the compiler. Here I just set the C++ version to use
CXXFLAGS = -std=c++14

main: LinkedList.h LinkedList.cpp main.cpp
	$(CXX) $(CXXFLAGS) LinkedList.cpp main.cpp -o main