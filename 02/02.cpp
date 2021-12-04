#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <assert.h>

namespace AOC
{
    enum class DirectionEnum
    {
        UP,
        DOWN,
        FORWARD,
        UNKNOWN
    };

    static DirectionEnum GetDirection(std::string const& keyword)
    {
        static std::unordered_map<std::string, DirectionEnum> const direction =
        {
            {"up", DirectionEnum::UP},
            {"down", DirectionEnum::DOWN},
            {"forward", DirectionEnum::FORWARD}
        };

        auto const& foundElement = direction.find(keyword);
        if (foundElement == direction.cend())
        {
            return DirectionEnum::UNKNOWN;
        }

        return foundElement->second;
    }
}

void part1(std::ifstream& inputFile)
{
    inputFile.clear();
    inputFile.seekg(0);

    std::string line{ "" };
    auto position = 0;
    auto depth = 0;
    while (std::getline(inputFile, line))
    {
        auto const kw = line.substr(0, line.find_first_of(' '));
        auto const number = std::stoi(line.substr(line.find_last_not_of(' '), line.size()));

        switch (AOC::GetDirection(kw))
        {
        case AOC::DirectionEnum::UP:
            depth -= number;
            break;
        case AOC::DirectionEnum::DOWN:
            depth += number;
            break;
        case AOC::DirectionEnum::FORWARD:
            position += number;
            break;
        default:
            std::cerr << "Unreachable default case reached!" << std::endl;
            break;
        }
    }
    std::cout << "[02] Part 1 Answer: " << position * depth << std::endl;
}

void part2(std::ifstream& inputFile)
{
    inputFile.clear();
    inputFile.seekg(0);

    std::string line{ "" };
    auto position = 0;
    auto depth = 0;
    auto aim = 0;
    while (std::getline(inputFile, line))
    {
        auto const kw = line.substr(0, line.find_first_of(' '));
        auto const number = std::stoi(line.substr(line.find_last_not_of(' '), line.size()));

        switch (AOC::GetDirection(kw))
        {
        case AOC::DirectionEnum::UP:
            aim -= number;
            break;
        case AOC::DirectionEnum::DOWN:
            aim += number;
            break;
        case AOC::DirectionEnum::FORWARD:
            position += number;
            depth += aim * number;
            break;
        default:
            std::cerr << "Unreachable default case reached!" << std::endl;
            break;
        }
    }
    std::cout << "[02] Part 2 Answer: " << position * depth << std::endl;
}

int main(void)
{
    std::ifstream inputFile{ "input.txt" };

    part1(inputFile);
    part2(inputFile);

    return 0;
}