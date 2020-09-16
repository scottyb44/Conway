#include <vector>

class Grid
{
public:
    Grid();
    void PrintToFile();
private:
    int xLength{20};
    int yLength{20};
    // TODO SB: Better way to represent the universe?
    std::vector<std::vector<int>> grid; 
};
