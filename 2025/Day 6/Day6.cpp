#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <string>
#include <algorithm>
#include <sstream>
#include <numeric>
using Strings = std::vector<std::string>;
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

Strings remove_spaces(const std::string &line)
{
    std::stringstream ss(line);
    Strings spaceless_line;
    std::string temp;

    while (ss >> temp)
    {
        spaceless_line.push_back(temp);
    }

    return spaceless_line;
}

long op(long a, long b)
{
    return a * b;
}

long calculate_problem(Strings column)
{
    char symbol;
    if (!column.empty())
    {
        symbol = column.back()[0];
        column.pop_back();
    }
    Longs problem(column.size());
    std::transform(column.begin(), column.end(), problem.begin(),
                   [](const std::string &s)
                   { return std::stol(s); });

    long solution;
    if (symbol == '+')
    {
        solution = std::accumulate(problem.begin(), problem.end(), 0);
    }
    else if (symbol == '*')
    {
        solution = std::accumulate(problem.begin(), problem.end(), 1, op);
    }
    return solution;
}

long part1(const Strings &lines)
{
    std::vector<Strings> spaceless_lines;
    for (const auto &line : lines)
    {
        spaceless_lines.push_back(remove_spaces(line));
    }

    long grand_total = 0;

    size_t num_columns = spaceless_lines[0].size();

    for (size_t col = 0; col < num_columns; ++col)
    {
        Strings column;
        for (const auto &row : spaceless_lines)
        {
            column.push_back(row[col]);
        }

        grand_total += calculate_problem(column);
    }

    return grand_total;
}

int main()
{
    // Print
    const auto input = read_input("input/input");

    // for (const auto &s : input)
    //     std::cout << s << std::endl;

    std::cout << "Part 1: " << part1(input) << "\n";
    // std::cout << "Part 2: " << part2(input) << "\n";

    return 0;
}