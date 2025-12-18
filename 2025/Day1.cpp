#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <functional>

using instructies = std::vector<std::string>;

enum class Richting
{
    Links,
    Rechts
};

struct Instructie
{
    int stapjes;
    Richting richting;

    Instructie(std::string line)
    {
        // R50
        // -> Richting::Rechts, 50 stapjes
        if (line[0] == 'R')
        {
            richting = Richting::Rechts;
        }
        else if (line[0] == 'L')
        {
            richting = Richting::Links;
        }
        stapjes = std::stoi(line.substr(1));
    }
};

void increase(int& dial) {
    dial++;
}

void decrease(int& dial) {
    dial--;
}

class Kluis
{
    int dial = 50;

public:
    int maketurn(const Instructie &instructie)
    {
        int count = 0;

        std::function<void(int&)> operation;
        if (instructie.richting == Richting::Links)
        {
            operation = decrease;
        }
        if (instructie.richting == Richting::Rechts)
        {
            operation = increase;
        }
        for (int i = 0; i < instructie.stapjes; i++)
        {
            operation(dial);
            if (dial > 99)
            {
                dial = 0;
            }
            if (dial < 0)
            {
                dial = 99;
            }
            if (dial ==0){
                count++;

            }
        }
        return count;
    }
};

int turnen(const instructies &instructies)
{
    int base = 100;
    int dial = 50;
    int step;
    int up = 0;
    char L = 'L';
    char R = 'R';

    for (int i = 0; i < instructies.size(); i++)
    {
        std::cout << dial << "," << instructies[i] << std::endl;
        if (instructies[i][0] == R)
        {
            step = std::stoi(instructies[i].substr(1));
            dial = (dial + step) % base;
        }
        else if (instructies[i][0] == L)
        {
            step = std::stoi(instructies[i].substr(1));
            dial = (dial - step) % base;
        }
        else
        {
            assert(false);
        }
        if (dial < 0)
        {
            dial = 100 + dial;
        }
        if (dial > 99)
        {
            assert(false);
        }
        if (dial == 0)
        {
            up += 1;
        }
    }

    return up;
}

instructies input(std::string filename)
{

    std::ifstream file(filename + ".txt");
    instructies turns;

    if (std::ifstream in{filename + ".txt"})
    {
        std::string turn;
        while (in >> turn)
        {
            turns.push_back(turn);
            std::cout << turn << std::endl;
        }
    }
    return turns;
}

int doedeel2(const instructies &instructies)
{
    Kluis kluis;
    int totaal = 0;

    for (const std::string &instructie : instructies)
    {
        totaal += kluis.maketurn(Instructie(instructie));
    }
    return totaal;
}

int main()
{

    // Print
    auto instructies = input("input");
    int answer = turnen(instructies);
    std::cout << "Number of zerooooos: " << answer << "\n";

    int answerdeel2 = doedeel2(instructies);
    std::cout << answerdeel2 << " keer langs 0 gekomen" << std::endl;
    return 0;
}