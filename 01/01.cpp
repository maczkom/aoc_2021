#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <numeric>

void part1(std::ifstream& inputFile) 
{
    // Reset file seek to beginning
    inputFile.clear();
    inputFile.seekg(0);

    std::string line{ "" };
    int largerCount = 0;
    int lastMeasure = -1;
    while (std::getline(inputFile, line))
    {
        auto currentMeasure = std::stoi(line);
        if (lastMeasure != -1 && lastMeasure < currentMeasure)
        {
            largerCount += 1;
        }
        lastMeasure = currentMeasure;
    }

    std::cout << "[01] Part 1 Answer: " << largerCount << std::endl;
}

void part2(std::ifstream& inputFile)
{
    // Reset file seek to beginning
    inputFile.clear();
    inputFile.seekg(0);

    std::string line{ "" };
    auto largerCount = 0;
    auto lastSum = -1;
    auto currentSum = -1;
    int window[3] = { -1, -1, -1 };
    for (auto elementIndex = 0; std::getline(inputFile, line); ++elementIndex)
    {
        auto currentNumber = std::stoi(line);
        window[elementIndex % 3] = currentNumber;
        
        // We don't have the first window ready
        if (window[2] == -1)
        {
            continue;
        }

        currentSum = std::accumulate(window, window + 3, 0);
        if (lastSum != -1 && lastSum < currentSum)
        {
            largerCount += 1;
        }
        lastSum = currentSum;
    }

    std::cout << "[01] Part 2 Answer: " << largerCount << std::endl;
}

int main(void)
{
    std::ifstream inputFile{ "input.txt" };

    part1(inputFile);
    part2(inputFile);

    return 0;
}