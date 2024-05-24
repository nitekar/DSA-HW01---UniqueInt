#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <filesystem>
#include <chrono>

class UniqueInt {
public:
    UniqueInt() : seen(2047, false), minInt(-1023) {}

    void processFile(const std::string &inputFilePath, const std::string &outputFilePath) {
        // Reset seen array for each file
        std::fill(seen.begin(), seen.end(), false);
        std::vector<int> uniqueNumbers = readUniqueIntegers(inputFilePath);
        writeUniqueIntegers(uniqueNumbers, outputFilePath);
    }

private:
    std::vector<bool> seen;
    const int minInt;

    std::vector<int> readUniqueIntegers(const std::string &inputFilePath) {
        std::vector<int> uniqueNumbers;
        std::ifstream inputFile(inputFilePath);
        std::string line;

        while (std::getline(inputFile, line)) {
            std::string strippedLine = trim(line);
            if (!strippedLine.empty() && isValidIntegerLine(strippedLine)) {
                int number = std::stoi(strippedLine);
                if (number >= -1023 && number <= 1023) {
                    if (!seen[number - minInt]) {
                        seen[number - minInt] = true;
                        uniqueNumbers.push_back(number);
                    }
                } else {
                    std::cout << "Number out of range: " << number << std::endl;
                }
            }
        }

        return sortUniqueNumbers(uniqueNumbers);
    }

    bool isValidIntegerLine(const std::string &line) {
        try {
            std::stoi(line);
            return true;
        } catch (const std::invalid_argument &e) {
            std::cout << "Invalid integer line: " << line << std::endl;
            return false;
        }
    }

    std::vector<int> sortUniqueNumbers(std::vector<int> &numbers) {
        std::sort(numbers.begin(), numbers.end());
        return numbers;
    }

    void writeUniqueIntegers(const std::vector<int> &uniqueNumbers, const std::string &outputFilePath) {
        std::ofstream outputFile(outputFilePath);
        for (int number : uniqueNumbers) {
            outputFile << number << "\n";
        }
    }

    std::string trim(const std::string &str) {
        size_t start = str.find_first_not_of(" \t");
        size_t end = str.find_last_not_of(" \t");
        return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
    }
};
int main() {
    const std::string inputFolder = "./Inputs";
    const std::string outputFolder = "./Output";

    UniqueInt uniqueIntProcessor;

    for (const auto &entry : std::filesystem::directory_iterator(inputFolder)) {
        if (entry.path().extension() == ".txt") {
            std::string inputPath = entry.path().string();
            std::string outputPath = outputFolder + "/" + entry.path().filename().string() + "_results.txt";

            // Timing for each file
            auto startTime = std::chrono::high_resolution_clock::now();
            uniqueIntProcessor.processFile(inputPath, outputPath);
            auto endTime = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> elapsed = endTime - startTime;
            std::cout << "Processed " << entry.path().filename().string() << " in " << elapsed.count() << " seconds" << std::endl;
        }
    }

    return 0;
} 
