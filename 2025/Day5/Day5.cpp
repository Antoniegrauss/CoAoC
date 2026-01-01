#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>

using Strings = std::vector<std::string>;
using Boolgrid = std::vector<std::vector<bool>>;
using Intgrid = std::vector<std::vector<int>>;

// Read input lines from a file with space between
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
    const auto input = read_input("input/input");
    const auto at_locations = at_mask(input);

    // for (const auto &s : input)
    //     std::cout << s << std::endl;

    std::cout << "Part 1: " << part1(at_locations) << "\n";
    std::cout << "Part 2: " << part2(at_locations) << "\n";

    return 0;
}