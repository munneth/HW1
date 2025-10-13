#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <tuple>
#include <algorithm>

class Book{
    private:
        int isbn;
        std::string type;
        std::string language;
    public:
        //getter's
        int getISBN() const {return isbn;}
        std::string getType() const {return type;}
        std::string getLanguage() const {return language;}

        //constructor
        Book(int isbn, std::string type, std::string language){
            this->isbn = isbn;
            this->type = type;
            this->language = language;
        };

        bool operator<(const Book& other) const {
            if(this->isbn != other.isbn){
                return this->isbn < other.isbn;
            }
            else if(this->type != other.type){
                std::vector<std::string> typeOrder = {"new", "used", "digital"};
                int thisIndex = -1, otherIndex = -1;
                
                for(int i = 0; i < typeOrder.size(); i++){
                    if (this->type == typeOrder[i]) thisIndex = i;
                    if (other.type == typeOrder[i]) otherIndex = i;
                }
                
                return thisIndex < otherIndex;
            }
            else{
                return this->language < other.language;
            }
        }

        bool operator==(const Book& other) const {
            return this->isbn == other.isbn && this->type == other.type && this->language == other.language;
        }
};

/*
* 2param
*/
std::vector<Book> readFile(const std::string& file){
    std::ifstream inputFile(file);
    std::vector<Book> books;
    std::string line;
    while (std::getline(inputFile, line)) {
        size_t comma1 = line.find(',');
        size_t comma2 = line.find(',', comma1 + 1);
        
        int isbn = std::stoi(line.substr(0, comma1));
        std::string language = line.substr(comma1 + 1, comma2 - comma1 - 1);
        std::string type = line.substr(comma2 + 1);
        
        books.push_back(Book(isbn, type, language));
        std::cout << line << std::endl;
    }
    return books;
}

int linSearch(std::vector<Book>& books, std::vector<Book>& requests){
    auto counter = 0;
    for(const auto& request : requests){
        for(const auto& book : books){
            if(book == request){
                std::cout << book.getISBN() << " " << book.getType() << " " << book.getLanguage() << std::endl;
                counter++;
                break;
            }
        }
    }
    return counter;
}

int binSearch(std::vector<Book>& books, std::vector<Book>& requests){
    auto counter = 0;

    for(const auto& request : requests){
        int low = 0;
        int high = books.size() - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if (books[mid] == request){
                counter++;
                break;
            }else if (books[mid] < request){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
    }
    return counter;
}

int recursiveBinSearchHelper(const std::vector<Book>& books, const Book& target, int low, int high) {
    if (low > high) {
        return 0; // Not found
    }
    
    int mid = low + (high - low) / 2;
    
    if (books[mid] == target) {
        return 1; // Found
    } else if (books[mid] < target) {
        return recursiveBinSearchHelper(books, target, mid + 1, high);
    } else {
        return recursiveBinSearchHelper(books, target, low, mid - 1);
    }
}

int recursiveBinSearch(const std::vector<Book>& books, const std::vector<Book>& requests) {
    auto counter = 0;
    
    for (const auto& request : requests) {
        counter += recursiveBinSearchHelper(books, request, 0, books.size() - 1);
    }
    
    return counter;
}

int getTypePriority(const std::string& type) {
    if (type == "new") return 0;
    if (type == "used") return 1;
    if (type == "digital") return 2;
    return 3; // Default for any other type
}

void sortBooks(std::vector<Book>& books){
    std::sort(books.begin(), books.end());
}

//std::string binarySearch(std::vector<std::string>& books, std::string& request){
    //sort books
    
//}

char getSearchMethod() {
    std::string input;
    
    while (true) {
        std::cout << "Choice of search method ([l]inear, [b]inary, [r]ecursiveBinary)? ";
        std::cin >> input;
        
        //check if input is exactly one character and is valid
        if (input.length() == 1) {
            char choice = tolower(input[0]);
            if (choice == 'l' || choice == 'b' || choice == 'r') {
                return choice;
            }
        }
        
        std::cout << "Incorrect choice" << std::endl;
    }
}



int main(int argc, char *argv[]){
    std::string newbooks = argv[1];
    std::string request = argv[2];
    std::vector<Book> newBooksVector = readFile(newbooks);
    std::vector<Book> requestVector = readFile(request);
    
    //char searchMethod = getSearchMethod();
    //std::cout << "Selected search method: " << searchMethod << std::endl;

    sortBooks(newBooksVector);
    for (const auto& book : newBooksVector){
        std::cout << book.getISBN() << " " << book.getType() << " " << book.getLanguage() << std::endl;
    }

    std::cout << "--------------------------------\nLinear Search\n--------------------------------\n";
    std::cout << linSearch(newBooksVector, requestVector) << std::endl;
    std::cout << "--------------------------------\nBinary Search\n--------------------------------\n";
    std::cout << binSearch(newBooksVector, requestVector) << std::endl;
    std::cout << "--------------------------------\nRecursive Binary Search\n--------------------------------\n";
    std::cout << recursiveBinSearch(newBooksVector, requestVector) << std::endl;
    return 0;
}
