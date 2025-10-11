#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <tuple>

class Book{
    private:
        int number;
        std::string language;
        std::string format;
    public:
        //getter's
        int getNumber(){return number;}
        std::string getLanguage(){return language;}
        std::string getFormat(){return format;}

        //constructor
        Book(int number, std::string language, std::string format){
            this->number = number;
            this->language = language;
            this->format = format;
        };
};

std::vector<std::string> readFile(const std::string& file){
    std::ifstream inputFile(file);
    std::vector<std::string> books;
    std::string line;
    std::cout << file << ": " << std::endl;
    while (std::getline(inputFile, line)) {
        books.push_back(line);
        std::cout << line << std::endl; 
    }
    return books;
}

std::string linSearch(std::vector<std::string>& books, std::string& request){
    for(const std::string& book : books){
        if(book == request){
            return book;
        }
    }
}

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
    std::vector<std::string> newBooksVector = readFile(newbooks);
    std::vector<std::string> requestVector = readFile(request);
    
    std::cout << "New books count: " << newBooksVector.size() << std::endl;
    for(const std::string& book : newBooksVector) {
        std::cout << "  " << book << std::endl;
    }
    
    std::cout << "Requests count: " << requestVector.size() << std::endl;
    for(const std::string& request : requestVector) {
        std::cout << "  " << request << std::endl;
    }
    
    char searchMethod = getSearchMethod();
    std::cout << "Selected search method: " << searchMethod << std::endl;
    
    return 0;
}
