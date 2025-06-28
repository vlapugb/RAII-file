#include "../src/raii_file.hpp"
#include <iostream>
#include <filesystem>

int main() {
    try {
        RaiiFile file("../test_files/1.txt", FileMode::WriteLine);
        file.writeLine("Допустим еще раз похвалили анекдот");
        file.writeLine("И еще разок");
    } catch (const std::exception& e) {
        std::cerr << "Error writing to file: " << e.what() << std::endl;
    }

    try {
        RaiiFile readFile("../test_files/1.txt", FileMode::ReadLine);
        std::cout << "First line: " << readFile.readLine(62) << std::endl;
        std::cout << "Second line: " << readFile.readLine(67) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error reading from file: " << e.what() << std::endl;
    }
    return 0;
}
