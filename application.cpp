#include <stdio.h>
#include <iostream>
#include "application.h"
#define PI 3.14159265358979323846

Application::Application(int rows, int cols):rows(rows), cols(cols){
    float crad=40.f;
    angle=0;
    frameRate=0;
    float gap=crad/2;
    scrW=(rows+1)*(crad*2)+(rows+2)*gap;
    scrH=(cols+1)*(crad*2)+(cols+2)*gap;
    window.create(sf::VideoMode(scrW, scrH), "SFML works!");
    float nextpos=gap;
    for(int n=0; n<cols; n++){
        nextpos+=crad*2+gap;
        circleCol.push_back(new Circle(gap, nextpos, crad, gap+crad, nextpos));
    }
    nextpos=gap;
    for(int n=0; n<rows; n++){
        nextpos+=crad*2+gap;
        circleRow.push_back(new Circle(nextpos, gap, crad, nextpos+crad, gap));
    }
    curves2=new Curve**[rows];
    for(int n=0; n<rows; n++){
        curves2[n]=new Curve*[cols];
    }
    for(int n=0; n<rows; n++){
        for(int m=0; m<cols; m++){
            curves2[n][m]=new Curve(circleCol[m]->py, circleRow[n]->px);
        }
    }

}
Application::~Application(){
    for(unsigned int n=0; n<circleCol.size(); n++){
        delete circleCol[n];
    }
    for(unsigned int n=0; n<circleRow.size(); n++){
        delete circleRow[n];
    }
    for(int n=0; n<rows; n++){
        for(int m=0; m<cols; m++){
            delete curves2[n][m];
        }
        delete[] curves2[n];
    }
    delete[] curves2;
}
void Application::mainloop(){
    window.setFramerateLimit(60);
    while(window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        update();
        draw();
        window.display();
    }

}
void Application::draw(){
    for(unsigned int n=0; n<circleCol.size(); n++){
        circleCol[n]->draw(window);
        sf::Vertex line[]={
            sf::Vertex(sf::Vector2f(circleCol[n]->px, circleCol[n]->py)),
            sf::Vertex(sf::Vector2f(scrW, circleCol[n]->py))
        };
        window.draw(line, 2, sf::Lines);
    }
    for (unsigned int n=0; n<circleRow.size(); n++){
        circleRow[n]->draw(window);
        sf::Vertex line[]={
            sf::Vertex(sf::Vector2f(circleRow[n]->px, circleRow[n]->py)),
            sf::Vertex(sf::Vector2f(circleRow[n]->px, scrH))
        };
        window.draw(line, 2, sf::Lines);
    }
    for(int n=0; n<rows; n++){
        for(int m=0; m<cols; m++){
            curves2[n][m]->draw(window);
        }
    }

}
void Application::update(){
    angle+=0.015;
    for(unsigned int n=0; n<circleCol.size(); n++){
        circleCol[n]->updatePointPos((n+1)*angle);
    }
    for(unsigned int n=0; n<circleRow.size(); n++){
        circleRow[n]->updatePointPos((n+1)*angle);
    }
    for(int n=0; n<rows; n++){
        for(int m=0; m<cols; m++){
            curves2[n][m]->addPoint(circleRow[n]->px, circleCol[m]->py);
        }
    }
    if(angle>=2*PI){
        for(int n=0; n<rows; n++){
            for(int m=0; m<cols; m++){
                curves2[n][m]->clear();
            }
        }
        angle=0;
    }
}
