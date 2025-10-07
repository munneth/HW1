#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <tuple>



void readFile(const std::string& file){
    std::ifstream inputFile(file);
    std::vector<std::tuple<std::string, std::string, std::string>> books;
    //std::cout << "Reading file: " << file << std::endl;
    std::string line;
    std::cout << file << ": " << std::endl;
    while (std::getline(inputFile, line)) {
        books.push_back(std::make_tuple(line));
        std::cout << line << std::endl; 
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

int main(int argc, char *argv[]){
    std::string newbooks = argv[1];
    std::string request = argv[2];
    readFile(newbooks);
    readFile(request);
    
    
    char searchMethod = getSearchMethod();
    std::cout << "Selected search method: " << searchMethod << std::endl;
    
    return 0;
}
