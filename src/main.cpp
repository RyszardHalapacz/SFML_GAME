#include "MyWindow.hpp"

int main()
{

    MyWindow window(sf::VideoMode(1000, 1000), "SFML");
    window.run();

    return 0;
}







































// //include <SFML/Graphics.hpp>
// #include "Person/person.h"
// int main()
// {
//     sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");

//     //Person person(100.0f, 90.0f);  // Tworzenie postaci z polem widzenia o promieniu 100 i kącie 120 stopni

//     //person.setPosition(window.getSize().x / 2, window.getSize().y / 2);

//     while (window.isOpen())
//     {
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed)
//                 window.close();
//         }

//         sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
//         //person.lookAt(mousePosition.x, mousePosition.y);
//         window.clear(sf::Color::Black);

//         // Rysowanie pola widzenia
//        // person.drawVisionField(window);

//         // Tutaj możesz sprawdzać, czy inne obiekty znajdują się w polu widzenia i podejmować odpowiednie działania

//         window.display();
//     }

//     return 0;
// }
