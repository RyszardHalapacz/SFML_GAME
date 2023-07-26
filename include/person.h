#pragma once

#include <SFML/Graphics.hpp>
#include "comon.h"
#include "FieldOfView.hpp"

class Person
{
public:
    Person(sf::RenderWindow& window,sf::Vector2f start_position, const sf::Color color = sf::Color::Red);

    void draw(const sf::Vector2f& cursorPosition,const sf::Vector2f& velocity);
    void setCursorPosition(const sf::Vector2f& cursorPosition);

private:
    sf::RenderWindow& window_;
    sf::CircleShape circle_;
    sf::Vector2f position_;
    sf::Vector2f cursorPosition_;
    float radius_= global::radius;
    float angle_=0;
    FieldOfView fieldOfView_;
};


