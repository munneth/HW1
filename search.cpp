#include "search.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

// Linear search implementation
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
int recursiveBinSearch(const std::vector<Book>& books, const std::vector<Book>& requests) {
  auto counter = 0;

  for (const auto& request : requests) {
    counter += recursiveBinSearchHelper(books, request, 0, books.size() - 1);
  }

  return counter;
}


// Sort books
void sortBooks(std::vector<Book>& books) {
  std::sort(books.begin(), books.end());
}

// Read file function
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
