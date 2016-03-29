#include "Tile.h"

Tile::Tile(float n_size, sf::Vector2f n_position, State n_state ) : m_size(n_size), position(n_position)
{
    shape = sf::RectangleShape();
    setState(n_state);
    setPosition(position);
    setSize(m_size);
}

void Tile::setSize(float n_size)
{
    m_size = n_size;
    shape.setSize(sf::Vector2f(m_size, m_size));
}

void Tile::setPosition(sf::Vector2f n_position)
{
    position = n_position;
    shape.setPosition(position);
}

float Tile::getSize()
{
    return m_size;
}

sf::Vector2f Tile::getPosition()
{
    return position;
}

void Tile::setState(State s)
{
    state = s;
    switch(state) {
    case State::EMPTY:
        setColor(sf::Color::Green);
        break;
    case State::WALL:
        setColor(sf::Color::Red);
        break;
    case State::DEPART:
        setColor(sf::Color::Blue);
        break;
    case State::GOAL:
        setColor(sf::Color::Cyan);
        break;
    default:
        setColor(sf::Color::White);
        break;
    }
}

void Tile::switchState()
{
    switch(state)
    {
    case State::EMPTY:
        setState(State::WALL);
        break;
    case State::WALL:
        setState(State::DEPART);
        break;
    case State::DEPART:
        setState(State::GOAL);
        break;
    case State::GOAL:
        setState(State::EMPTY);
        break;
    }
}

void Tile::setColor(sf::Color c)
{
    color = c;
    shape.setFillColor(color);
}

void Tile::checkState(const sf::RenderWindow &window)
{
        if (shape.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
        {
            switchState();
            return;
        }
}

Tile::~Tile()
{
    //dtor
}
