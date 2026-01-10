#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <string>
#include <numeric>
#include <algorithm>

using Strings = std::vector<std::string>;
using Tile = std::pair<long, long>;
using Coords = std::vector<Tile>;

// Read input lines from a file
Coords read_input(const std::string &filename)
{
    std::ifstream in(filename + ".txt");
    assert(in && "Could not open input file");

    Coords coordinates;
    for (std::string line; std::getline(in, line);)
    {
        auto commaPos = line.find(',');
        assert(commaPos != std::string::npos && "Invalid coordinate format");

        int x = std::stoi(line.substr(0, commaPos));
        int y = std::stoi(line.substr(commaPos + 1));

        coordinates.emplace_back(x, y);
    }

    return coordinates;
}

long part1(Coords coordinates)
{
    std::sort(coordinates.begin(), coordinates.end());
    long max_area = 0;
    size_t n_tiles = coordinates.size();
    for (size_t r = 0; r < n_tiles; ++r)
    {
        for (size_t c = r + 1; c < n_tiles; ++c)
        {
            long area = (coordinates[c].first - coordinates[r].first + 1) * (coordinates[c].second - coordinates[r].second + 1);
            if (area > max_area)
                max_area = area;
        }
    }
    return max_area;
}

int main()
{
    // Print
    const auto input = read_input("input/input");

    // for (const auto &tile : input)
    //{
    //     std::cout << "(" << tile.first << ", " << tile.second << ")\n";
    // }

    std::cout << "Part 1: " << part1(input) << "\n";
    // std::cout << "Part 2: " << part2(input) << "\n";

    return 0;
}