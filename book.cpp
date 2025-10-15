#include "book.h"
#include <vector>

// Constructor
// build objects wit the given values
Book::Book(int isbn, std::string type, std::string language) {
  this->isbn = isbn;
  this->type = type;
  this->language = language;
}

// Getters
// allows you to call values from the book object
int Book::getISBN() const { return isbn; }
std::string Book::getType() const { return type; }
std::string Book::getLanguage() const { return language; }

// Operators
bool Book::operator<(const Book& other) const {
  if (this->isbn != other.isbn) {
    return this->isbn < other.isbn;
  } else if (this->type != other.type) {
    // allows for the sorting of the books by type
    // assigns index value of the type of the book to the book
    // the types are ordered the vector the way they are supposed to be sorted
    // when index is assigned the index of the type is compared to the other index of the type
    std::vector<std::string> typeOrder = {"new", "used", "digital"};
    int thisIndex = -1, otherIndex = -1;

    for (size_t i = 0; i < typeOrder.size(); i++) {
      if (this->type == typeOrder[i]) thisIndex = i;
      if (other.type == typeOrder[i]) otherIndex = i;
    }

    
    return thisIndex < otherIndex;
  } else {
    return this->language < other.language;
  }
}
// this simply check if the books are equal by comparing the values of the books
// instead of all of the books objects there are three values tghat are comapred and determine if the books are equal
bool Book::operator==(const Book& other) const {
  return this->isbn == other.isbn && this->type == other.type &&
         this->language == other.language;
}
