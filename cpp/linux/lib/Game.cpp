#include "Game.h"

void Game::PrintGridToFile()
{
    m_grid.PrintToFile();
}

void Game::RunLife()
{
    //for (int i = 0; i < 10; ++i)
    for (int i = 0; i < 2; ++i)
    {
        m_grid.PrintToFile(i);
        m_grid.Evolve();
    }
}
