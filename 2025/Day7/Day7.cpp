#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <string>
#include <numeric>

using Strings = std::vector<std::string>;
using BeamPositions = std::vector<int>;
using Timelines = std::vector<long>;

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

BeamPositions process_row(const BeamPositions &previous_beam_positions, std::string &row, int &split_count, Timelines &timelines)
{
    BeamPositions beam_positions;

    for (const auto &beam : previous_beam_positions)
    {
        if (beam < 0 || beam >= static_cast<int>(row.size()))
        {
            continue;
        }
        char &cell = row[beam];

        if (cell == '|')
        {
            continue;
        }

        if (cell == '.')
        {
            cell = '|';
            beam_positions.push_back(beam);
        }
        else if (cell == '^')
        {
            ++split_count;
            if (beam > 0)
            {
                timelines[beam - 1] += timelines[beam];
                row[beam - 1] = '|';
                beam_positions.push_back(beam - 1);
            }
            if (beam + 1 < row.size())
            {
                timelines[beam + 1] += timelines[beam];
                row[beam + 1] = '|';
                beam_positions.push_back(beam + 1);
            }

            timelines[beam] = 0;
        }
    }
    return beam_positions;
}

int part1(const Strings &lines)
{
    int split_count = 0;
    Strings manifold = lines;
    BeamPositions beam_positions;
    Timelines dummy_timelines(lines[0].size(), 0);

    auto start = lines[0].find('S');
    assert(start != std::string::npos && "Start position 'S' not found");
    beam_positions.push_back(static_cast<int>(start));

    for (size_t row = 1; row < manifold.size(); ++row)
    {
        beam_positions = process_row(beam_positions, manifold[row], split_count, dummy_timelines);
    }
    return split_count;
}

long part2(const Strings &lines)
{
    int split_count = 0;
    Timelines timelines(lines[0].size(), 0);
    Strings manifold = lines;
    BeamPositions beam_positions;

    auto start = lines[0].find('S');
    assert(start != std::string::npos && "Start position 'S' not found");
    beam_positions.push_back(static_cast<int>(start));
    timelines[start] = 1;

    for (size_t row = 1; row < manifold.size(); ++row)
    {
        beam_positions = process_row(beam_positions, manifold[row], split_count, timelines);
    }
    return std::accumulate(timelines.begin(), timelines.end(), 0L);
}

int main()
{
    // Print
    const auto input = read_input("input/input");

    // for (const auto &s : input)
    //     std::cout << s << std::endl;

    std::cout << "Part 1: " << part1(input) << "\n";
    std::cout << "Part 2: " << part2(input) << "\n";

    return 0;
}
