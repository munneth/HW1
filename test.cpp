#include <cassert>
#include <iostream>
#include <vector>
#include <algorithm>
#include "book.h"
#include "search.h"

// Linear Search Tests
void test_linear_hit() {
    std::vector<Book> newbooks = {Book(123, "new", "english")};
    std::vector<Book> requests = {Book(123, "new", "english")};
    assert(linSearch(newbooks, requests) == 1);
}

void test_linear_miss() {
    std::vector<Book> newbooks = {Book(123, "new", "english")};
    std::vector<Book> requests = {Book(124, "new", "english")};
    assert(linSearch(newbooks, requests) == 0);
}

void test_linear_empty() {
    std::vector<Book> newbooks = {};
    std::vector<Book> requests = {Book(123, "new", "english")};
    assert(linSearch(newbooks, requests) == 0);
}

void test_linear_duplicates() {
    std::vector<Book> newbooks = {Book(123, "new", "english"), Book(123, "new", "english")};
    std::vector<Book> requests = {Book(123, "new", "english")};
    assert(linSearch(newbooks, requests) == 1);
}

// Binary Search Tests
void test_binary_hit() {
    std::vector<Book> newbooks = {Book(123, "new", "english")};
    std::vector<Book> requests = {Book(123, "new", "english")};
    sortBooks(newbooks);
    assert(binSearch(newbooks, requests) == 1);
}

void test_binary_miss() {
    std::vector<Book> newbooks = {Book(123, "new", "english")};
    std::vector<Book> requests = {Book(124, "new", "english")};
    sortBooks(newbooks);
    assert(binSearch(newbooks, requests) == 0);
}

void test_binary_empty() {
    std::vector<Book> newbooks = {};
    std::vector<Book> requests = {Book(123, "new", "english")};
    assert(binSearch(newbooks, requests) == 0);
}

void test_binary_duplicates() {
    std::vector<Book> newbooks = {Book(123, "new", "english"), Book(123, "new", "english")};
    std::vector<Book> requests = {Book(123, "new", "english")};
    sortBooks(newbooks);
    assert(binSearch(newbooks, requests) == 1);
}

// Recursive Binary Search Tests
void test_recursive_binary_hit() {
    std::vector<Book> newbooks = {Book(123, "new", "english")};
    std::vector<Book> requests = {Book(123, "new", "english")};
    sortBooks(newbooks);
    assert(recursiveBinSearch(newbooks, requests) == 1);
}

void test_recursive_binary_miss() {
    std::vector<Book> newbooks = {Book(123, "new", "english")};
    std::vector<Book> requests = {Book(124, "new", "english")};
    sortBooks(newbooks);
    assert(recursiveBinSearch(newbooks, requests) == 0);
}

void test_recursive_binary_empty() {
    std::vector<Book> newbooks = {};
    std::vector<Book> requests = {Book(123, "new", "english")};
    assert(recursiveBinSearch(newbooks, requests) == 0);
}

void test_recursive_binary_duplicates() {
    std::vector<Book> newbooks = {Book(123, "new", "english"), Book(123, "new", "english")};
    std::vector<Book> requests = {Book(123, "new", "english")};
    sortBooks(newbooks);
    assert(recursiveBinSearch(newbooks, requests) == 1);
}

// Book Comparator Tests
void test_book_equals() {
    Book book1(123, "new", "english");
    Book book2(123, "new", "english");
    Book book3(123, "used", "english");
    Book book4(124, "new", "english");
    
    assert(book1 == book2);  // Same book should be equal
    assert(!(book1 == book3));  // Different type should not be equal
    assert(!(book1 == book4));  // Different ISBN should not be equal
}

void test_book_less_than() {
    Book book1(123, "new", "english");
    Book book2(124, "new", "english");
    Book book3(122, "new", "english");
    
    assert(book1 < book2);   // Lower ISBN should be less than higher ISBN
    assert(book3 < book1);   // Lower ISBN should be less than higher ISBN
    assert(book3 < book2);   // Lower ISBN should be less than higher ISBN
}

void test_book_sorting() {
    std::vector<Book> books = {
        Book(300, "new", "english"),
        Book(100, "new", "english"),
        Book(200, "new", "english")
    };
    
    std::sort(books.begin(), books.end());
    
    // Should be sorted by ISBN
    assert(books[0].getISBN() == 100);
    assert(books[1].getISBN() == 200);
    assert(books[2].getISBN() == 300);
}

int main() {
    std::cout << "Running Linear Search Tests..." << std::endl;
    test_linear_hit();
    test_linear_miss();
    test_linear_empty();
    test_linear_duplicates();
    
    std::cout << "Running Binary Search Tests..." << std::endl;
    test_binary_hit();
    test_binary_miss();
    test_binary_empty();
    test_binary_duplicates();
    
    std::cout << "Running Recursive Binary Search Tests..." << std::endl;
    test_recursive_binary_hit();
    test_recursive_binary_miss();
    test_recursive_binary_empty();
    test_recursive_binary_duplicates();
    
    std::cout << "Running Book Comparator Tests..." << std::endl;
    test_book_equals();
    test_book_less_than();
    test_book_sorting();
    
    std::cout << "All unit tests passed!" << std::endl;
    return 0;
}