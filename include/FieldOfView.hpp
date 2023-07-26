#pragma once

#include <SFML/Graphics.hpp>
#include "comon.h"

class FieldOfView
{
public:
    FieldOfView(sf::RenderWindow& window,sf::Vector2f position,
    float angle, 
     const sf::Color color = sf::Color::White);

    void update(const sf::Vector2f &personPosition,
               // const sf::Vector2f &cursorPosition,
                float rotation,
                float radius);
    void draw(sf::RenderWindow &window);
    bool isInField(sf::Vector2f point,sf::Vector2f dis,float angle_, float olddist);

private:
    sf::RenderWindow& window_;
    sf::VertexArray fieldOfView_;
    sf::Transform transform_;
    float radius_ = global::radiusFieldofView;
    sf::Color startColor_ ;//= sf::Color::White;
    float rot = 0;
    sf::Vector2f personPosition_;
    float angle_;
};
