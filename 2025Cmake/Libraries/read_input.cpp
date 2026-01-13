#include <fstream>
#include <cassert>

#include "Include/read_input.hpp"

std::vector<std::string> read_input(const std::string &filename)
{
    std::ifstream in(filename + ".txt");
    assert(in && "Could not open input file");

    std::vector<std::string> ranges;
    for (std::string s; std::getline(in, s, ',');)
        ranges.push_back(s);

    return ranges;
}
