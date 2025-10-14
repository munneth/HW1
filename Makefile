# Simple Makefile for SearchNewBooks
CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11

# Main program
SearchNewBooks: SearchNewBooks.cpp book.cpp search.cpp timer.cpp
	$(CXX) $(CXXFLAGS) -o SearchNewBooks SearchNewBooks.cpp book.cpp search.cpp timer.cpp

# Simple tests
test: test.cpp book.cpp search.cpp timer.cpp
	$(CXX) $(CXXFLAGS) -o test test.cpp book.cpp search.cpp timer.cpp
	./test

# Google Test (requires gtest library)
gtest: hello_test.cc book.cpp search.cpp timer.cpp
	$(CXX) $(CXXFLAGS) -o gtest hello_test.cc book.cpp search.cpp timer.cpp -lgtest -lgtest_main -pthread
	./gtest

# Clean up all generated files
clean:
	rm -f SearchNewBooks test gtest *.o *.dat

.PHONY: test gtest clean