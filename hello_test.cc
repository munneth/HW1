#include <gtest/gtest.h>
#include "book.h"
#include "search.h"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);

  
}
//linear testss
TEST(LinearSearch, BasicAssertions) {
    std::vector<Book> newbooks = {Book(123, "new", "english")};
    std::vector<Book> requests = {Book(123, "new", "english")};
    EXPECT_EQ(linSearch(newbooks, requests), 1);
}

TEST(LinearSearch, Miss) {
    std::vector<Book> newbooks = {Book(123, "new", "english")};
    std::vector<Book> requests = {Book(124, "new", "english")};
    EXPECT_EQ(linSearch(newbooks, requests), 0);
}

TEST(LinearSearch, Empty) {
    std::vector<Book> newbooks = {};
    std::vector<Book> requests = {Book(123, "new", "english")};
    EXPECT_EQ(linSearch(newbooks, requests), 0);
}

TEST(LinearSearch, Duplicates) {
    std::vector<Book> newbooks = {Book(123, "new", "english"), Book(123, "new", "english")};
    std::vector<Book> requests = {Book(123, "new", "english")};
    EXPECT_EQ(linSearch(newbooks, requests), 1);
}


//binnary test
TEST(BinarySearch, BasicAssertions) {
    std::vector<Book> newbooks = {Book(123, "new", "english")};
    std::vector<Book> requests = {Book(123, "new", "english")};
    EXPECT_EQ(binSearch(newbooks, requests), 1);
}

TEST(BinarySearch, Miss) {
    std::vector<Book> newbooks = {Book(123, "new", "english")};
    std::vector<Book> requests = {Book(124, "new", "english")};
    EXPECT_EQ(binSearch(newbooks, requests), 0);
}

TEST(BinarySearch, Empty) {
    std::vector<Book> newbooks = {};
    std::vector<Book> requests = {Book(123, "new", "english")};
    EXPECT_EQ(binSearch(newbooks, requests), 0);
}

TEST(BinarySearch, Duplicates) {
    std::vector<Book> newbooks = {Book(123, "new", "english"), Book(123, "new", "english")};
    std::vector<Book> requests = {Book(123, "new", "english")};
    EXPECT_EQ(binSearch(newbooks, requests), 1);
}

//recursive binary test
TEST(RecursiveBinarySearch, BasicAssertions) {
    std::vector<Book> newbooks = {Book(123, "new", "english")};
    std::vector<Book> requests = {Book(123, "new", "english")};
    EXPECT_EQ(recursiveBinSearch(newbooks, requests), 1);
}

TEST(RecursiveBinarySearch, Miss) {
    std::vector<Book> newbooks = {Book(123, "new", "english")};
    std::vector<Book> requests = {Book(124, "new", "english")};
    EXPECT_EQ(recursiveBinSearch(newbooks, requests), 0);
}

TEST(RecursiveBinarySearch, Empty) {
    std::vector<Book> newbooks = {};
    std::vector<Book> requests = {Book(123, "new", "english")};
    EXPECT_EQ(recursiveBinSearch(newbooks, requests), 0);
}

TEST(RecursiveBinarySearch, Duplicates) {
    std::vector<Book> newbooks = {Book(123, "new", "english"), Book(123, "new", "english")};
    std::vector<Book> requests = {Book(123, "new", "english")};
    EXPECT_EQ(recursiveBinSearch(newbooks, requests), 1);
}