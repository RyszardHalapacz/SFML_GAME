
#pragma once

#include <SFML/Graphics.hpp>
#include <array>
#include "person.h"
#include <vector>
class MyWindow : public sf::RenderWindow
{
public:
    MyWindow(sf::VideoMode mode, const sf::String& title);

    void run();

private:
    void handleEvent(const sf::Event& event);
    void render();

    Person person_;
    sf::Vector2f cursorPosition_;
    sf::Vector2f velocity_;
    std::array<bool, 4> isKeyPressed_ {false, false,false,false};
};