#include "../headers/circulo.hpp"

Circulo::Circulo():centro(make_unique<Punto>(0.0f,0.0f)),radio(0){}
Circulo::Circulo(float x, float y, float r): centro(make_unique<Punto>(x,y)), radio(r){}
Circulo::Circulo(unique_ptr<Punto> c, float r): centro(move(c)), radio(r){}

void Circulo::setCentro(unique_ptr<Punto> c) {
    if(c!=nullptr){
        centro = move(c);
    }
    else{cout<<"ERROR: El centro no puede ser nulo, mantiene el centro original"<<endl;}
}
void Circulo::setCentro(float x, float y) {centro = make_unique<Punto>(x,y);}
void Circulo::setRadio(float r) {
    if(r>0.0f) radio = r;
    else cout<<"ERROR: El radio debe ser mayor a cero";//si r<=0 mantiene el radio original
}
const Punto& Circulo::getCentro() const {return *centro;}
float Circulo::getRadio() const {return radio;}

void Circulo::imprimir()const{
    cout<<"====Circulo===="<<endl;
    cout<<"Centro = ("<<centro->getX()<<" ; "<<centro->getY()<<")"<<endl;
    cout<<"Radio = "<<radio<<endl;
}