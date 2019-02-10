#include "curve.h"

Curve::Curve(float startx, float starty){

}
Curve::~Curve(){

}
void Curve::addPoint(float x, float y){
    points.push_back(Coordinate(x, y));
}
void Curve::draw(sf::RenderWindow &window){
    std::vector<sf::Vertex> curve;
    for(unsigned int n=0; n<points.size(); n++){
        curve.push_back(sf::Vertex(sf::Vector2f(points[n].x, points[n].y)));
    }
    window.draw(&curve[0], curve.size(), sf::LineStrip);
}
void Curve::clear(){
    points.clear();
}
