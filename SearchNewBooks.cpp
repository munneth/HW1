#include <iostream>
#include <string>
#include <fstream>



void readFile(const std::string& file){
    std::ifstream inputFile(file);

    //std::cout << "Reading file: " << file << std::endl;
    std::string line;
    std::cout << file << ": " << std::endl;
    while (std::getline(inputFile, line)) {
        
        std::cout << line << std::endl; 
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
    return 0;
}
