#include "../src/raii_file.hpp"
#include <iostream>
#include <filesystem>

int main() {
    try {
        RaiiFile file("../test_files/incorrect_extension.bibabobo", FileMode::WriteLine);
        file.writeLine("Хороший анекдот!");
        file.writeLine("Мне нравится этот анекдот!");
    } catch (const std::exception& e) {
        std::cerr << "Error writing to file: " << e.what() << std::endl;
    }
    return 0;
}
