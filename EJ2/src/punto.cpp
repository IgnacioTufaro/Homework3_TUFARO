#include "../headers/punto.hpp"

Punto::Punto():punto(make_pair(0.0f,0.0f)){}
Punto::Punto(float x, float y):punto(make_pair(x,y)){}

void Punto::setCoords(float x, float y){
    punto.first = x;
    punto.second = y;
}
void Punto::setX(float x){ punto.first = x;}
void Punto::setY(float y){ punto.second = y;}

const pair<float, float> Punto::getCoords() const {return punto;}
float Punto::getX() const {return punto.first;}
float Punto::getY() const {return punto.second;}

void Punto::imprimir() const{
    cout<<"Punto = ("<<punto.first<<" ; "<<punto.second<<")"<<endl;
}