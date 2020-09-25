#include <vector>

class Grid
{
public:
    Grid();
    void PrintToFile(int iteration = 0);
    void Evolve();
private:
    int xLength{20};
    int yLength{20};
    // TODO SB: Better way to represent the universe?
    std::vector<std::vector<int>> m_grid; 

    int CountNeighbors(int x, int y);
    int RangedCount(int minX, int maxX, int minY, int maxY);
    bool CellIsOnBoundary(int x, int y);
    int CountBoundaryCells(int x, int y);
};
