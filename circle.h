#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED
#include <SFML/Graphics.hpp>

class Circle{
    float x, y;
    int originx, originy;
    float rad;
    sf::CircleShape shape;

public:
    float px, py;
    Circle(float x, float y, float rad, float px, float py);
    ~Circle();
    void draw(sf::RenderWindow &window);
    void updatePointPos(float angle);
private:

};

#endif // CIRCLE_H_INCLUDED
