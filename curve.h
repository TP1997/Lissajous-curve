#ifndef CURVE_H_INCLUDED
#define CURVE_H_INCLUDED
#include <vector>
#include <SFML/Graphics.hpp>
struct Coordinate{
    float x;
    float y;
    Coordinate(float x_, float y_):x(x_), y(y_){};
};
class Curve{
    std::vector<Coordinate> points;
    std::vector<sf::Vertex> vetices;
public:
    Curve(float startx, float starty);
    ~Curve();
    void addPoint(float x, float y);
    void draw(sf::RenderWindow &window);
    void clear();
};

#endif // CURVE_H_INCLUDED
