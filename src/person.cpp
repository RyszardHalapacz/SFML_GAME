#include "person.h"
#include <cmath>
#include <iostream>
Person::Person(sf::RenderWindow& window,sf::Vector2f start_position,const sf::Color color) :
        window_(window),
        position_(start_position),
        fieldOfView_(window,position_, angle_)
{
    circle_.setOrigin(sf::Vector2f(radius_/2,radius_/2));
    circle_.setPosition(position_);
    circle_.setRadius(radius_);
    circle_.setFillColor(sf::Color::Red);
}

void Person::draw( const sf::Vector2f& cursorPosition , const sf::Vector2f& velocity )
{

    position_ += velocity;
    sf::Vector2f direction = cursorPosition - position_;
     angle_ = std::atan2(direction.y, direction.x) * 180.f / 3.14159f;

    fieldOfView_.update(position_,angle_,radius_);
    sf::Vertex line[] =
    {
        sf::Vertex(position_),
        sf::Vertex(cursorPosition)
    };
    fieldOfView_.draw(window_);
    window_.draw(circle_);
    circle_.setPosition(position_ );
    window_.draw(line, 2, sf::Lines);
    //std::cout << position_.x << " "<< position_.y << circle_.getPosition().x << " "
    //<< circle_.getPosition().y<<"\n";
}

void Person::setCursorPosition(const sf::Vector2f& cursorPosition)
    {
        cursorPosition_ = cursorPosition;
    }
