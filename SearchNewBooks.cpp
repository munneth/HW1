#include <iostream>
#include <string>
#include <fstream>



void readFile(const std::string& newbooks, const std::string& request){
    std::ifstream inputFile(newbooks);
    std::ifstream inputFile(request);

    std::cout << "Reading file: " << newbooks << std::endl;
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
        }
}

int main(int argc, char *argv[]){
    std::string newbooks = argv[1];
    std::string request = argv[2];
    readFile(newbooks, request);
    return 0;
}
