#include "../headers/elipse.hpp"

//Constructor default, inicializa en 0.0
Elipse::Elipse():centro(make_unique<Punto>(0.0f,0.0f)),semi_ejes(make_pair(0.0f,0.0f)){}
//Constructor por parametros
Elipse::Elipse(float x, float y, float a, float b): centro(make_unique<Punto>(x,y)){
    if(a>=b){semi_ejes = make_pair(a,b);}
    else{semi_ejes = make_pair(b,a);}
}
Elipse::Elipse(unique_ptr<Punto> c, float a, float b): centro(move(c)),semi_ejes(make_pair(a,b)){}

void Elipse::setCentro(unique_ptr<Punto> c) {
    if(c!=nullptr){
        centro = move(c);
    }
    else{cout<<"ERROR: El centro no puede ser nulo, mantiene el centro original"<<endl;}
}
void Elipse::setCentro(float x, float y) {centro = make_unique<Punto>(x,y);}                    
void Elipse::setSemiEjeMayor(float a) {
    if(a>0.0f) semi_ejes.first = a;
    else cout<<"ERROR: el semi eje debe ser mayor a cero";
}
void Elipse::setSemiEjeMenor(float b){
    if(b>0.0f) semi_ejes.first = b;
    else cout<<"ERROR: el semi eje debe ser mayor a cero";
}

const Punto& Elipse::getCentro() const {return *centro;}
float Elipse::getSemiEjeMayor() const {return semi_ejes.first;}
float Elipse::getSemiEjeMenor() const {return semi_ejes.second;}

void Elipse::imprimir()const{
    cout<<"====Elipse===="<<endl;
    cout<<"Centro = ("<<centro->getX()<<" ; "<<centro->getY()<<")"<<endl;
    cout<<"Semieje mayor = "<<semi_ejes.first<<endl;
    cout<<"Semieje menor = "<<semi_ejes.second<<endl;
}