#include <vector>

class Grid
{
public:
    Grid();
    void PrintToFile();
private:
    int xLength{20};
    int yLength{20};
    std::vector<std::vector<int>> grid; 
};
