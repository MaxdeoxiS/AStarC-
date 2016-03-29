#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

    enum class State : int{
        EMPTY,
        WALL,
        DEPART,
        GOAL,
        WAY
    };
class Tile
{
    public:
                            Tile(float n_size, sf::Vector2f position, State n_state );
        void                setSize(float n_size);
        void                setPosition(sf::Vector2f n_position);
        float               getSize();
        sf::Vector2f        getPosition();
        sf::RectangleShape  getShape() { return shape;}
        sf::Color           getColor() { return color; }
        void                setState(State s);
        State               getState() { return state; }
        void                setColor(sf::Color c);
        void                switchState();
        void                checkState(const sf::RenderWindow &window);



        virtual ~Tile();
    protected:
    private:
        sf::RectangleShape  shape;
        sf::Color           color;
        State               state;
        sf::Vector2f        position;
        float               m_size;
        int                 x, y;
};

#endif // TILE_H
