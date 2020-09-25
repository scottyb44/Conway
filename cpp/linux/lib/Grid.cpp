#include "Grid.h"
#include <cstdlib>
#include <exception>
#include <fstream>
#include <iostream>
#include <string>

static int MIN_UNI{0};
static int MAX_UNI{0};

Grid::Grid()
    //: xLength{20}
    //, yLength{20}
    : xLength{5}
    , yLength{5}
    , m_grid(xLength, std::vector<int>(yLength))
{
// TODO SB: This assume a square universe lets support different configurations
    MAX_UNI = m_grid.size() - 1;
    srand((unsigned) time(0));
    for (auto& row : m_grid)
    {
        for (auto& item : row)
        {
            item = rand() % 2;
        }
    }
}

void Grid::Evolve()
{
    // TODO SB: Find a better way than this
    for (int i = 0; i < m_grid.size(); ++i)
    {
        for (int j = 0; j < m_grid[i].size(); ++j)
        {
            // TODO SB: Make a function here
            const auto neighbors = CountNeighbors(i, j);
//            std::cout << "NEIGHBORS: " << neighbors << std::endl;
            if (2 > neighbors)
            {
                m_grid[i][j] = 0;
            }
            else if (1 == m_grid[i][j] && (2 == neighbors || 3 == neighbors))
            {
                m_grid[i][j] = 1;
            }
            else if (3 > neighbors)
            {
                m_grid[i][j] = 0;
            }
            else if (0 == m_grid[i][j] && 3 == neighbors)
            {
                m_grid[i][j] = 1;
            }
        }
    }
 //   std::cout << "SHOULD BE DONE HERE!!!!!!!!!!!!!!!!" << std::endl;
}

int Grid::CountNeighbors(int x, int y)
{
  //  std::cout << "COUNT NEIGHBORS: " << x << ", " << y << std::endl;
    int count = 0;
    // TODO SB: Seems like we could find if were on the boundar once per corner and then scan and not have to check again
    if (!CellIsOnBoundary(x, y))
    {
        count = RangedCount(-1, 1, -1, 1);
    }
    else 
    {
        count = CountBoundaryCells(x, y);
    }
   return count; 
}

// TODO SB: This method seems dumb as hell
int Grid::CountBoundaryCells(int x, int y)
{
    // corners first
    if (MIN_UNI == x && MIN_UNI == y)
    {
        // 0, +1 x and y
        return RangedCount(0, 1, 0, 1);
    }
    else if (MIN_UNI == x && MAX_UNI == y)
    {
        // x: 0, -1
        // y: 0, +1
        return RangedCount(-1, 0, 0, 1);
    }
    else if (MAX_UNI == x && MIN_UNI == y)
    {
        // x: 0, +1
        // y: 0, -1
        return RangedCount(0, 1, -1, 0);
    }
    else if (MAX_UNI == x && MAX_UNI == y)
    {
        // x: 0, -1
        // y: 0, -1
        return RangedCount(-1, 0, -1, 0);
    }

    // bars next
    // top bar
    if (MIN_UNI == x)
    {
        // x: -1, 1
        // y: 0, 1
        return RangedCount(-1, 1, 0, 1);
    }
    // bottom bar
    else if (MAX_UNI == x)
    {
        // x: -1, 1
        // y: 0, -1
        return RangedCount(-1, 1, -1, 0);
    }
    // left bar
    else if (MIN_UNI == y)
    {
        // x: 0, 1
        // y: -1, 1
        return RangedCount(0, 1, -1, 1);
    }
    // right bar
    else if (MAX_UNI == y)
    {
        // x: 0, -1
        // y: -1, 1
        return RangedCount(-1, 0, -1, 1);
    }
    //throw std::exception{"Arent on boundary"};
    throw std::exception();
}

int Grid::RangedCount(int minX, int maxX, int minY, int maxY)
{
    int count = 0;
    for (int i = minX; i <= maxX; ++i)
    {
        for (int j = minY; j < maxY; ++j)
        {
            if (0 == i && 0 == j)
            {
                continue;
            }
            count += m_grid[i][j];
        }
    }
}


bool Grid::CellIsOnBoundary(int x, int y)
{
    return (MIN_UNI == x || MAX_UNI == x) || (MIN_UNI == y || MAX_UNI == y);
}

void Grid::PrintToFile(int iteration)
{
    std::string fileName{ "Universe" + std::to_string(iteration) + ".txt" };
    std::ofstream output;
    output.open(fileName);
    for (const auto& row : m_grid)
    {
        for (const auto& item : row)
        {
            output << item << " ";
        }
        output << "\n";
    }
    output.close();
}
