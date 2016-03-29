#include <iostream>
#include <SFML/Graphics.hpp>
#include "MapSearchNode.h"

const int MAP_WIDTH = 10;
const int MAP_HEIGHT = 10;

std::vector<std::vector<int>> world_map(MAP_WIDTH, std::vector<int>(MAP_HEIGHT, 1));

void runAstar(Board b);

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Test");

    Board b(world_map);

	vector<Tile*> tiles = b.getTiles();
    vector<Tile*>::iterator it;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    for(it = tiles.begin(); it != tiles.end(); it++)
                    {
                        (*it)->checkState(window);
                    }
                    b.updateGrid();
                }
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Numpad0)
                {
                    runAstar(b);
                }
                if (event.key.code == sf::Keyboard::Down)
                {
                    b.resetGrid();
                }
                if (event.key.code == sf::Keyboard::Left)
                {
                    b.deletePath();
                }
            }
        }

        window.clear();

        for(it = tiles.begin(); it != tiles.end(); it++)
        {
            window.draw((*it)->getShape());
        }
        window.display();
    }

    return 0;
}

void runAstar(Board b)
{
    AStarSearch<MapSearchNode> astarsearch;

    // Create a start state
    MapSearchNode nodeStart;
    nodeStart.x = b.getDepart().x;
    nodeStart.y = b.getDepart().y;

    // Define the goal state
    MapSearchNode nodeEnd;
    nodeEnd.x = b.getGoal().x;//b.getDepart().x + 2;//b.getGoal().x;
    nodeEnd.y = b.getGoal().y;//b.getDepart().y + 2;//b.getGoal().y;

    unsigned int SearchState;
    unsigned int SearchSteps = 0;

    astarsearch.SetStartAndGoalStates( nodeStart, nodeEnd );

    do
    {
        SearchState = astarsearch.SearchStep();
        SearchSteps++;
    }
    while( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SEARCHING );

    if( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SUCCEEDED )
    {
            MapSearchNode *node = astarsearch.GetSolutionStart();

            node->PrintNodeInfo(b);
            for( ;; )
            {
                node = astarsearch.GetSolutionNext();

                if( !node )
                {
                    break;
                }

                node->PrintNodeInfo(b);
            };
            astarsearch.FreeSolutionNodes();
    }
}
