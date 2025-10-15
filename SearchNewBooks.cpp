#include "book.h"
#include "search.h"
#include "timer.h"
#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
  // read in arguments
  std::string newbooks = argv[1];
  std::string request = argv[2];
  //check if there is a third argument for output file otherwise call it found.dat
  std::string output;
  if (argc > 3) {
    output = argv[3];
  } else {
    output = "found.dat";
  }
  // read in the files
  std::vector<Book> newBooksVector = readFile(newbooks);
  std::vector<Book> requestVector = readFile(request);
  // start timer and create object to call print elapsed time
  Timer ct;
  
  // get search method preferred and store it
  char choice = getSearchMethod();
  int count = 0;
  // decides which search method to use based on the choice variable
  if (choice == 'l') {
    //std::cout << "--------------------------------\nLinear "
    //             "Search\n--------------------------------\n";
    ct.Reset();
    count = linSearch(newBooksVector, requestVector);
    std::cout << count << std::endl;
    // when search is done the time is printed and stopped also the count is called above it 
    ct.printElapsedTime();
  } else if (choice == 'b') {
    // sort the books vector
    sortBooks(newBooksVector);
    //std::cout << "--------------------------------\nBinary "
    //             "Search\n--------------------------------\n";
    ct.Reset();
    count = binSearch(newBooksVector, requestVector);
    std::cout << count << std::endl;
    // when search is done the time is printed and stopped also the count is called above it 
    ct.printElapsedTime();
  } else if (choice == 'r') {
    sortBooks(newBooksVector);
    //std::cout << "--------------------------------\nRecursive Binary "
    //             "Search\n--------------------------------\n";
    ct.Reset();
    count = recursiveBinSearch(newBooksVector, requestVector);
    std::cout << count << std::endl;
    ct.printElapsedTime();
  }
  
  // write result to file at the end of the program
  std::ofstream outputFile(output);
  if (outputFile.is_open()) {
    outputFile << count << std::endl;
    outputFile.close();
  }
  
  return 0;
}