# Simple Makefile to build SearchNewBooks from SearchNewBooks.cpp

CXX = g++
CXXFLAGS = -Wall -Werror
TARGET = SearchNewBooks
SRC = SearchNewBooks.cpp

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET) *.o newbooks.dat requests.dat request.dat
