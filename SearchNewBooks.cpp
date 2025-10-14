#include "book.h"
#include "search.h"
#include "timer.h"
#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
  std::string newbooks = argv[1];
  std::string request = argv[2];
  std::string output;
  if (argc > 3) {
    output = argv[3];
  } else {
    output = "found.dat";
  }
  std::vector<Book> newBooksVector = readFile(newbooks);
  std::vector<Book> requestVector = readFile(request);

  Timer ct;
  ct.Reset();
  char choice = getSearchMethod();
  int count = 0;
  
  if (choice == 'l') {
    //std::cout << "--------------------------------\nLinear "
    //             "Search\n--------------------------------\n";
    count = linSearch(newBooksVector, requestVector);
    std::cout << count << std::endl;
    ct.printElapsedTime();
  } else if (choice == 'b') {
    sortBooks(newBooksVector);
    //std::cout << "--------------------------------\nBinary "
    //             "Search\n--------------------------------\n";
    count = binSearch(newBooksVector, requestVector);
    std::cout << count << std::endl;
    ct.printElapsedTime();
  } else if (choice == 'r') {
    sortBooks(newBooksVector);
    //std::cout << "--------------------------------\nRecursive Binary "
    //             "Search\n--------------------------------\n";
    count = recursiveBinSearch(newBooksVector, requestVector);
    std::cout << count << std::endl;
    ct.printElapsedTime();
  }
  
  // Write result to file
  std::ofstream outputFile(output);
  if (outputFile.is_open()) {
    outputFile << count << std::endl;
    outputFile.close();
  }
  
  return 0;
}