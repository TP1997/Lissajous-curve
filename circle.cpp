#include "circle.h"
#define PI 3.14159265358979323846

Circle::Circle(float x, float y,float rad,float px,float py):x(x), y(y), rad(rad), px(px), py(py){
    originx=x+rad;
    originy=y+rad;
    shape.setPosition(x, y);
    shape.setRadius(rad);
    shape.setFillColor(sf::Color::White);

}
Circle::~Circle(){

}
void Circle::updatePointPos(float angle){
    px=originx+rad*cos(angle);
    py=originy+rad*sin(angle);
}

void Circle::draw(sf::RenderWindow &window){
    sf::CircleShape tempshape;
    tempshape.setPosition(originx-38.f,originy-38.f);
    tempshape.setRadius(38.f);
    tempshape.setFillColor(sf::Color::Black);

    sf::CircleShape dot;
    dot.setPosition(px-4.f, py-4.f);
    dot.setRadius(4.f);
    dot.setFillColor(sf::Color::White);

    window.draw(shape);
    window.draw(tempshape);
    window.draw(dot);
}
