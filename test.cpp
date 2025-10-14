#include <cassert>
#include <iostream>
#include <vector>
#include "book.h"
#include "search.h"

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

int main() {
    test_linear_hit();
    test_linear_miss();
    std::cout << "All unit tests passed!" << std::endl;
    return 0;
}