#include "../src/raii_file.hpp"
#include <iostream>
#include <filesystem>

int main() {
    try {
        RaiiFile readFile("../test_files/1.txt", FileMode::ReadLine);
        std::cout << "First line: " << readFile.readLine(29) << std::endl;
        std::cout << "Second line: " << readFile.readLine(40) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error reading from file: " << e.what() << std::endl;
    }
    return 0;
}
