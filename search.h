#ifndef SEARCH_H
#define SEARCH_H

#include "book.h"
#include <vector>

// Search functions
int linSearch(std::vector<Book>& books, std::vector<Book>& requests);
int binSearch(std::vector<Book>& books, std::vector<Book>& requests);
int recursiveBinSearch(const std::vector<Book>& books, const std::vector<Book>& requests);

// Helper functions
int recursiveBinSearchHelper(const std::vector<Book>& books, const Book& target, int low, int high);
void sortBooks(std::vector<Book>& books);

// File operations
std::vector<Book> readFile(const std::string& file);

// User interface
char getSearchMethod();

#endif
