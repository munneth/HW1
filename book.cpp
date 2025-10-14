#include "book.h"
#include <vector>

// Constructor
Book::Book(int isbn, std::string type, std::string language) {
  this->isbn = isbn;
  this->type = type;
  this->language = language;
}

// Getters
int Book::getISBN() const { return isbn; }
std::string Book::getType() const { return type; }
std::string Book::getLanguage() const { return language; }

// Operators
bool Book::operator<(const Book& other) const {
  if (this->isbn != other.isbn) {
    return this->isbn < other.isbn;
  } else if (this->type != other.type) {
    std::vector<std::string> typeOrder = {"new", "used", "digital"};
    int thisIndex = -1, otherIndex = -1;

    for (int i = 0; i < typeOrder.size(); i++) {
      if (this->type == typeOrder[i]) thisIndex = i;
      if (other.type == typeOrder[i]) otherIndex = i;
    }

    return thisIndex < otherIndex;
  } else {
    return this->language < other.language;
  }
}

bool Book::operator==(const Book& other) const {
  return this->isbn == other.isbn && this->type == other.type &&
         this->language == other.language;
}
