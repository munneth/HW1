#include <iostream>
#include <string>
#include <fstream>



void readFile(const std::string& newbooks.dat, const std::string& request.dat){
    std::ifstream inputFile(newbooks.dat);
    std::ifstream inputFile(request.dat);

    std::cout << "Reading file: " << newbooks.dat << std::endl;
}

int main(int argc, char *argv[]){
    readFile(argv[1], argv[2]);
    return 0;
}
