#include "Board.h"


Board::Board(std::vector<std::vector<int>> newGrid)
{
    world_map = newGrid;
    m_dimensions.x = newGrid[0].size();
    m_dimensions.y = newGrid.size();
    int maxDim = getMaxDim();
    float mSize = (800/maxDim) - (800/maxDim)/15;

    updateGraphicalGrid(world_map);

}

int Board::getMaxDim()
{
    if(m_dimensions.x > m_dimensions.y)
        return m_dimensions.x;
    return m_dimensions.y;
}

void Board::updateGrid()
{
    for(int j = 0; j < m_dimensions.x; j++)
    {
        for(int i = 0; i < m_dimensions.y; i++)
        {
            switch(grid[(m_dimensions.y)*j + i]->getState())
            {
            case State::EMPTY:
                world_map[i][j] = 1;
                break;
            case State::WALL:
                world_map[i][j] = 9;
                break;
            default:
                world_map[i][j] = 1;
                break;
            }
        }
    }
}


sf::Vector2i Board::getDepart()
{
    for(int j = 0; j < m_dimensions.x; j++)
    {
        for(int i = 0; i < m_dimensions.y; i++)
        {
            if(grid[(m_dimensions.y)*j + i]->getState() == State::DEPART)
            {
                return sf::Vector2i(i, j);
            }
        }
    }
    return sf::Vector2i(0,0);
}

sf::Vector2i Board::getGoal()
{
    for(int j = 0; j < m_dimensions.x; j++)
    {
        for(int i = 0; i < m_dimensions.y; i++)
        {
            if(grid[(m_dimensions.y)*j + i]->getState() == State::GOAL)
            {
                return sf::Vector2i(i, j);
            }
        }
    }
    return sf::Vector2i(0,0);
}

void Board::resetGrid()
{
    int maxDim = getMaxDim();
    float mSize = (800/maxDim) - (800/maxDim)/15;
    for(int j = 0; j < m_dimensions.x; j++)
    {
        for(int i = 0; i < m_dimensions.y; i++)
        {
                getTiles()[(j * m_dimensions.y) + i]->setState(State::EMPTY);
        }
    }

    updateGrid();
}

void Board::deletePath()
{

}

void Board::updateGraphicalGrid(std::vector<std::vector<int>> newGrid)
{
    int maxDim = getMaxDim();
    float mSize = (800/maxDim) - (800/maxDim)/15;

    for(int j = 0; j < m_dimensions.x; j++)
    {
        for(int i = 0; i < m_dimensions.y; i++)
        {
        Tile* t;
            if(newGrid[i][j] == 1)
            {
                t = new Tile(mSize, sf::Vector2f(i * mSize + (mSize/15)*i, j * mSize + (mSize/15)*j), State::EMPTY);//(rand() % 255, rand() % 255, rand() % 255));
            }
            else if(newGrid[i][j] == 9)
            {
                t = new Tile(mSize, sf::Vector2f(i * mSize + (mSize/15)*i, j * mSize + (mSize/15)*j), State::WALL);//(rand() % 255, rand() % 255, rand() % 255));
            }
            else
            {
                t = new Tile(mSize, sf::Vector2f(i * mSize + (mSize/15)*i, j * mSize + (mSize/15)*j), State::DEPART);//(rand() % 255, rand() % 255, rand() % 255));
            }
            grid.push_back(t);
        }
    }
}


Board::~Board()
{
    //dtor
}
