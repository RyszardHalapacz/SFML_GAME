#include "MyWindow.hpp"

MyWindow::MyWindow(sf::VideoMode mode, const sf::String& title)
    : sf::RenderWindow(mode, title),
      person_(*this, sf::Vector2f(400.f, 400.f))
{
    setFramerateLimit(50);
}

void MyWindow::run()
{
    while (isOpen())
    {
        sf::Event event;
        while (pollEvent(event))
        {
            handleEvent(event);

            if (event.type == sf::Event::Closed)
                close();
        }

        render();
    }
}

void MyWindow::handleEvent(const sf::Event& event)
{
   if (event.type == sf::Event::MouseMoved)
    {
        cursorPosition_ = sf::Vector2f(event.mouseMove.x, event.mouseMove.y);
        person_.setCursorPosition(cursorPosition_);
    }
    if (event.type == sf::Event::KeyPressed)
    {
        
        if (event.key.code == sf::Keyboard::W)
            isKeyPressed_[0] = true;
        else if (event.key.code == sf::Keyboard::S)
            isKeyPressed_[1] = true;
        else if (event.key.code == sf::Keyboard::A)
            isKeyPressed_[2] = true;
        else if (event.key.code == sf::Keyboard::D)
            isKeyPressed_[3] = true;
    }
    else if (event.type == sf::Event::KeyReleased)
    {
        
        if (event.key.code == sf::Keyboard::W)
            isKeyPressed_[0] = false;
        else if (event.key.code == sf::Keyboard::S)
            isKeyPressed_[1] = false;
        else if (event.key.code == sf::Keyboard::A)
            isKeyPressed_[2] = false;
        else if (event.key.code == sf::Keyboard::D)
            isKeyPressed_[3] = false;
    }
}
void MyWindow::render()
{
    clear();  

    if (isKeyPressed_[0]) 
        velocity_.y -= global::speed;
    if (isKeyPressed_[1]) 
        velocity_.y += global::speed;
    if (isKeyPressed_[2]) 
        velocity_.x -= global::speed;
    if (isKeyPressed_[3]) 
        velocity_.x += global::speed;


    person_.draw( cursorPosition_,velocity_);
    velocity_ = sf::Vector2f(0.0f, 0.0f); 


    display();
}

