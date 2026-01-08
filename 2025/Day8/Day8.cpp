#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <string>
#include <numeric>

using Strings = std::vector<std::string>;
using Ints = std::vector<int>;
using Longs = std::vector<long>;

// Read input lines from a file
Strings read_input(const std::string &filename)
{
    std::ifstream in(filename + ".txt");
    assert(in && "Could not open input file");

    Strings lines;
    for (std::string line; std::getline(in, line);)
        lines.push_back(line);

    return lines;
}

int main()
{
    // Print
    const auto input = read_input("input/testinput");

    for (const auto &s : input)
        std::cout << s << std::endl;

    // std::cout << "Part 1: " << part1(input) << "\n";
    // std::cout << "Part 2: " << part2(input) << "\n";

    return 0;
}
