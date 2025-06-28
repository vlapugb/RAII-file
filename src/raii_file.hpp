#include <filesystem>
#include <iostream>
#include <fstream>
namespace fs = std::filesystem;

enum class FileMode {
    WriteLine,
    ReadLine
};

class RaiiFile {
    private:
        std::fstream fileStream;
    public:
        RaiiFile(const fs::path& path, FileMode mode);
        const std::string& readLine(size_t lineNumber);
        void writeLine(const std::string &inputLine);
        ~RaiiFile();
};