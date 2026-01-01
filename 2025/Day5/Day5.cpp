#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>

using Strings = std::vector<std::string>;
using Longs = std::vector<long>;
using Longrid = std::vector<Longs>;

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

// Convert stringranges into long array with begin/end of range in every row
Longrid build_ranges(const Strings &rangelines)
{
    Longrid ranges;
    for (const auto &str : rangelines)
    {
        std::vector<long> row;
        row.reserve(rangelines.size());
        row[0] = std::stol(str);
        int dash_location = std::find(str.begin(), str.end(), '-');
        row[1] = std::stol(str.substr(dash_location + 1));
        ranges.push_back(row);
    }
    return ranges;
}

Strings slice_vector(const Strings &vec, int start, int end)
{
    return Strings(vec.begin() + start, vec.begin() + end);
}

int part1(const Strings &lines)
{
    int emptyline = std::find(lines.begin(), lines.end(), "");
    Strings rangelines = slice_vector(lines, 0, emptyline - 1);
    Longrid ranges = build_ranges(rangelines);
    Strings ingredients = slice_vector(lines, emptyline + 1, static_cast<int>(lines.end()));
    // needs to be converted to Longs

    int result;

    for (const auto ingredient : ingredients)
    {
        std::vector<long> row;
        row.reserve(ranges.size());
        for (row : ranges)
        {
            if (ingredient >= row[0] && ingredient <= row[1])
                ++result;
            break;
        }
    }
    return result;
}

int main()
{
    // Print
    const auto input = read_input("input/testinput");

    // for (const auto &s : input)
    //     std::cout << s << std::endl;

    std::cout << "Part 1: " << part1(read_input) << "\n";
    // std::cout << "Part 2: " << part2(at_locations) << "\n";

    return 0;
}