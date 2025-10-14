#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>

class Book {
 private:
  int isbn;
  std::string type;
  std::string language;

 public:
  // Constructor
  Book(int isbn, std::string type, std::string language);
  
  // Getters
  int getISBN() const;
  std::string getType() const;
  std::string getLanguage() const;

  // Operators
  bool operator<(const Book& other) const;
  bool operator==(const Book& other) const;
};

#endif
