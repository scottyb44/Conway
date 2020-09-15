#include "Grid.h"
#include <fstream>

Grid::Grid()
    : xLength{20}
    , yLength{20}
    , grid{ xLength, std::vector<int>{ yLength, 0 } }
{
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
