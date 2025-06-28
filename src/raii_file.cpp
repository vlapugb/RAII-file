#include "raii_file.hpp"
#include <vector>
#include <algorithm>

RaiiFile::RaiiFile(const fs::path& path, FileMode mode) {
    std::vector<std::string> allowed = {".txt", ".cfg", ".log"};
    std::string fileExt = static_cast<std::string>(path.extension());
    switch (mode)
        {
        case FileMode::ReadLine:
            fileStream.open(path, std::ios::in);
            break;
        case FileMode::WriteLine:
            fileStream.open(path, std::ios::out | std::ios::app);
            break;
        default:
            throw std::invalid_argument("Invalid file mode");
        }
        if (!fileStream.is_open()) {
            throw std::runtime_error("Failed to open file: " + path.string());
        }
        if (std::find(allowed.begin(), allowed.end(), fileExt) == allowed.end()) {
            throw std::invalid_argument("Invalid file extension: " + fileExt);
        }
}

const std::string& RaiiFile::readLine(size_t lineNumber)
{
    fileStream.clear();
    fileStream.seekg(0);
    std::string currentLine = "";
    while(std::getline(fileStream, currentLine)) {
        if (lineNumber == 0) {
            return currentLine;
        }
        --lineNumber;
    }
    throw std::out_of_range("Value of read line number is out of range");
}

void RaiiFile::writeLine(const std::string &inputLine)
{
    if(inputLine.empty()) {
        throw std::invalid_argument("Input line cannot be empty");
    }
    fileStream << inputLine << std::endl;
}

RaiiFile::~RaiiFile(){
    if(fileStream.is_open()) {
        fileStream.close();
    }
}
