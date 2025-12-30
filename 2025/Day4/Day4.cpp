#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <cmath>

using Strings = std::vector<std::string>;
using Longs = std::vector<long>;

Strings read_input(const std::string &filename)
{
    std::ifstream in(filename + ".txt");
    assert(in && "Could not open input file");

    Strings lines;
    std::string s;
    while (std::getline(in, s))
    {
        if (!s.empty())
            lines.push_back(s);
    }
    return lines;
}

int main()
{
    // Print
    auto instructions = read_input("input/testinput");
    for (const auto &s : instructions)
        std::cout << s << std::endl;

    // int answer1 = part1(instructions);
    // std::cout << "Part 1: " << answer1 << std::endl;

    // long answer2 = part2(instructions);
    // std::cout << "Part 2: " << answer2 << std::endl;
    return 0;
}