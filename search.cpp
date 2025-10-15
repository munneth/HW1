#include "search.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

// Linear search implementation
// loop through requests and books and check if they are equal
// this runs in O(n^2) time
// nested for loop adds to counter if a match is found
int linSearch(std::vector<Book>& books, std::vector<Book>& requests) {
  auto counter = 0;
  for (const auto& request : requests) {
    for (const auto& book : books) {
      if (book == request) {
        counter++;
        break;
      }
    }
  }
  return counter;
}

// Binary search implementation
// loop through requests and books and check if they are equal
// this runs in O(nlogn) time
// binary search is used to find the book in the books vector
// if the book is found, the counter is incremented
// if the book is not found, the counter is not incremented
int binSearch(std::vector<Book>& books, std::vector<Book>& requests) {
  auto counter = 0;

  for (const auto& request : requests) {
    int low = 0;
    int high = books.size() - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (books[mid] == request) {
        counter++;
        break;
      } else if (books[mid] < request) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
  }
  return counter;
}

// Recursive binary search helper
// this runs in O(logn) time
// essentially is binary search however it recurses if there is not a match found
// called within a for loop for each request book in the recursive bin search
int recursiveBinSearchHelper(const std::vector<Book>& books, const Book& target, int low, int high) {
  if (low > high) {
    return 0;  
  }

  int mid = low + (high - low) / 2;

  if (books[mid] == target) {
    return 1;  
  } else if (books[mid] < target) {
    return recursiveBinSearchHelper(books, target, mid + 1, high);
  } else {
    return recursiveBinSearchHelper(books, target, low, mid - 1);
  }
}

// Recursive binary search
// this runs in O(nlogn) time
// a foor loop that is used to call the recursive bin search helper for each request book
int recursiveBinSearch(const std::vector<Book>& books, const std::vector<Book>& requests) {
  auto counter = 0;

  for (const auto& request : requests) {
    counter += recursiveBinSearchHelper(books, request, 0, books.size() - 1);
  }

  return counter;
}


// Sort books
// essentially just uess std::sort which utilizes operators such as == and < to make its decisions these operators are
// overloaded under the hood in the book class specially < and ==
void sortBooks(std::vector<Book>& books) {
  std::sort(books.begin(), books.end());
}

// Read file function
// we ues a while loops to read the file and find the commas so we know how to parse the line
// we then parse it into the variables that we need

std::vector<Book> readFile(const std::string& file) {
  std::ifstream inputFile(file);
  std::vector<Book> books;
  std::string line;
  while (std::getline(inputFile, line)) {
    size_t comma1 = line.find(',');
    size_t comma2 = line.find(',', comma1 + 1);
//didnt let me ussse C cast here
    int isbn = std::stoi(line.substr(0, comma1));
    std::string language = line.substr(comma1 + 1, comma2 - comma1 - 1);
    std::string type = line.substr(comma2 + 1);
//create array of objects
// this adds to vector by pushing back the book object
// using objects instead of usual values allows us to use the operators == and < to make its decisions and call other functions
// on these members
    books.push_back(Book(isbn, type, language));
  }
  return books;
}

// Get search method from user
char getSearchMethod() {
  std::string input;

  while (true) {
    std::cout << "Choice of search method ([l]inear, [b]inary, [r]ecursiveBinary)? ";
    std::cin >> input;

    
    if (input.length() == 1) {
      char choice = tolower(input[0]);
      if (choice == 'l' || choice == 'b' || choice == 'r') {
        return choice;
      }
    }

    std::cout << "Incorrect choice" << std::endl;
  }
}
