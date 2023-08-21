#include "FieldOfView.hpp"
#include <cmath>
#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

void prepare(std::vector<sf::CircleShape>& vecCircle)
{
    float x =500,y=500;
    for(int i =0;i<2;i++)
    {
    sf::CircleShape zombie;
    zombie.setOrigin(sf::Vector2f(global::radius/2,global::radius/2));
    zombie.setPosition(sf::Vector2f(x,y));
    zombie.setRadius(global::radius);
    zombie.setFillColor(sf::Color::Green);
    vecCircle.push_back(zombie);
    x+=150;
    y+=150;
    }

};




FieldOfView::FieldOfView(sf::RenderWindow& window,sf::Vector2f position,  float angle, const sf::Color color)
:window_(window)
{
    angle_ = angle; 
    personPosition_ = position; 
}


bool FieldOfView::isInField(sf::Vector2f point, sf::Vector2f dis,float angle_, float olddist)
{
    sf::Vector2f direction = point - personPosition_;
    float angle = std::atan2(direction.y, direction.x) * 180.f / M_PI;
    float distance = std::sqrt(std::pow((dis.x - personPosition_.x), 2) + std::pow((dis.y - personPosition_.y), 2));
   if (distance <= olddist)// && angle > angle_ - 1.5f && angle < angle_ + 1.5f;
   {
    //std:: cout << "\ndistance: "<< distance <<" olddistan" << olddist;
    return (angle > angle_ - 1.f && angle < angle_ + 1.f);
   }
   return false;
}



void FieldOfView::update(const sf::Vector2f& curPersonPositionx,
                         //const sf::Vector2f& cursorPosition, 
                         float rotation, float radiusPerson)
{
    std::vector<sf::CircleShape> zombie;
    prepare(zombie);
    //std::for_each(zombie.begin(), zombie.end(), [this](auto& it) { window_.draw(it); });
    

    sf::Vector2f personPosition = curPersonPositionx;
    personPosition_= curPersonPositionx;
    angle_ =rotation;
    float leftAngle = angle_ - 60.0f; 
    float rightAngle = angle_ + 60.0f; 

    int numPoints = 100; 
    float angleStep = (rightAngle - leftAngle) / numPoints; 

    transform_ = sf::Transform::Identity;
    transform_.rotate(rotation, personPosition_);

    fieldOfView_.setPrimitiveType(sf::PrimitiveType::TriangleFan);
    fieldOfView_.resize(numPoints + 2); 

   // personPosition += sf::Vector2f(radiusPerson / 2.f, radiusPerson / 2.f);
    fieldOfView_[0].position = personPosition; 
    sf::Vector2f pointInField;

    for (int i = 0; i <= numPoints; ++i) 
    {
        float currentAngle = leftAngle + angleStep * i;
        float x = personPosition.x + radius_ * std::cos(currentAngle * M_PI / 180.f);
        float y = personPosition.y + radius_ * std::sin(currentAngle * M_PI / 180.f);
        auto xx = x;
        auto yy = y;
        float xxx=500,yyy=500;
        float distance = std::sqrt((x - personPosition.x) * (x - personPosition.x) + (y - personPosition.y) * (y - personPosition.y));
        float ratio = distance / radius_;
        
        sf::Color color = sf::Color(
            startColor_.r * (1.f - ratio), 
            startColor_.g * (1.f - ratio), 
            startColor_.b * (1.f - ratio)
        );
        for(auto & z : zombie)
        {
            auto isDrawed= false;
            for(auto i=0; i<z.getPointCount();i++)
            {
                if(isInField(sf::Vector2f(z.getPoint(i).x+xxx,z.getPoint(i).y+yyy),
                sf::Vector2f(x,y),
                currentAngle,
                distance ))
                {
                    // if(!isDrawed && i == z.getPointCount()-1)
                    // {window_.draw(z);
                    // isDrawed= true;
                    // }
                    //std::cout<<"\n  y = z.getPoint(i)" << z.getPoint(i).x+xxx
                    //<<"\n  y = z.getPoint(i)" << z.getPoint(i).y+yyy;
                 xx = z.getPoint(i).x+xxx;
                 yy = z.getPoint(i).y+yyy;
                 distance = std::sqrt((x - personPosition.x) * (x - personPosition.x) + (y - personPosition.y) * (y - personPosition.y));
                }
            }
            xxx+=150;
            yyy+=150;
        }

        fieldOfView_[i + 1].position = sf::Vector2f(xx, yy);
        fieldOfView_[i + 1].color = color;
    }
   

    transform_ = sf::Transform::Identity;
}

void FieldOfView::draw(sf::RenderWindow& window)
{
    window.draw(fieldOfView_, transform_);
    std::vector<sf::CircleShape> zombie;
    prepare(zombie);
     std::for_each(zombie.begin(), zombie.end(), [this](auto& it) { 
            auto isDrawed = false;
         for(auto i=0; i<it.getPointCount();i++)
         {
            if(!isDrawed && i == it.getPointCount()-1)
                    {
                        window_.draw(it);
                        isDrawed= true;
                    }
         }
        //window_.draw(it); 
        });
}
