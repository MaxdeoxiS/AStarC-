#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>
#include "Tile.h"
#include <vector>

#include <iostream>

extern std::vector<std::vector<int>> world_map;
extern const int MAP_WIDTH;
extern const int MAP_HEIGHT;

static int GetMap( int x, int y)
{
	if( x < 0 ||
	    x >= MAP_WIDTH ||
		 y < 0 ||
		 y >= MAP_HEIGHT
	  )
	{
		return 9;
	}

	return world_map[x][y];
}

class Board
{
    public:
        Board(std::vector<std::vector<int>> newGrid);
        std::vector<Tile*> getTiles() { return grid; }
        int getMaxDim();
        void updateGrid();
        sf::Vector2i getDepart();
        sf::Vector2i getGoal();
        void resetGrid();
        void deletePath();
        void updateGraphicalGrid(std::vector<std::vector<int>> newGrid);


        virtual ~Board();
    protected:
    private:
        std::vector<Tile*> grid;
        sf::Vector2i m_dimensions;
};

#endif // BOARD_H
