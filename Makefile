CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET = SearchNewBooks
TEST_TARGET = test

# Source files
MAIN_SRC = SearchNewBooks.cpp
BOOK_SRC = book.cpp
SEARCH_SRC = search.cpp
TIMER_SRC = timer.cpp
TEST_SRC = test.cpp

# Object files
MAIN_OBJ = $(MAIN_SRC:.cpp=.o)
BOOK_OBJ = $(BOOK_SRC:.cpp=.o)
SEARCH_OBJ = $(SEARCH_SRC:.cpp=.o)
TIMER_OBJ = $(TIMER_SRC:.cpp=.o)
TEST_OBJ = $(TEST_SRC:.cpp=.o)

# Default target
all: $(TARGET) $(TEST_TARGET)

# Main program
$(TARGET): $(MAIN_OBJ) $(BOOK_OBJ) $(SEARCH_OBJ) $(TIMER_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Test program
$(TEST_TARGET): $(TEST_OBJ) $(BOOK_OBJ) $(SEARCH_OBJ) $(TIMER_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f *.o $(TARGET) $(TEST_TARGET)

# Run tests
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Run main program with test data
run: $(TARGET)
	./$(TARGET) newbooks.dat request.dat

.PHONY: all clean test run