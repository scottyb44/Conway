#include "Grid.h"
#include <cstdlib>
#include <fstream>

Grid::Grid()
    : xLength{20}
    , yLength{20}
    , grid(xLength, std::vector<int>(yLength))
{
    srand((unsigned) time(0));
    for (auto& row : grid)
    {
        for (auto& item : row)
        {
            item = rand() % 2;
        }
    }
}

void Grid::PrintToFile()
{
    std::ofstream output;
    output.open("Grid.txt");
    for (const auto& row : grid)
    {
        for (const auto& item : row)
        {
            output << item << " ";
        }
        output << "\n";
    }
    output.close();
}
