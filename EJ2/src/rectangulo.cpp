#include "../headers/rectangulo.hpp"

//Constructor default
Rectangulo::Rectangulo():EsqIzq(make_unique<Punto>(0.0f,0.0f)),ancho(0.0f),largo(0.0f){}
//Constructores con parametros iniciales
Rectangulo::Rectangulo(float x,float y,float a,float l):EsqIzq(make_unique<Punto>(x,y)),ancho(a),largo(l){}
Rectangulo::Rectangulo(unique_ptr<Punto> esq, float a, float l): EsqIzq(move(esq)),ancho(a),largo(l){}

void Rectangulo::setEsqIzq(unique_ptr<Punto> esq) {
    if(esq!=nullptr){
        EsqIzq=move(esq);
    }
    else{cout<<"ERROR: El vertice inferior no puede ser nulo, mantiene el vertice original"<<endl;}
}
void Rectangulo::setEsqIzq(float x, float y){EsqIzq = make_unique<Punto>(x,y);}   //HAY QUE VERIFICAR QUE ANCHO < LARGO?????????
void Rectangulo::setAncho(float a){
    if(a>0.0f) ancho = a;
    else cout<<"ERROR: el ancho debe ser mayor a cero";
}
void Rectangulo::setLargo(float l){
    if(l>0.0f) largo = l;
    else cout<<"ERROR: el largo debe ser mayor a cero";
}

const Punto& Rectangulo::getEsqIzq() const {return *EsqIzq;} 
float Rectangulo::getAncho() const {return ancho;}
float Rectangulo::getLargo() const {return largo;}

void Rectangulo::imprimir() const{
    cout<<"====Rectangulo===="<<endl;
    cout<<"Vertice inferior izquierdo = ("<<EsqIzq->getX()<<" ; "<<EsqIzq->getY()<<")"<<endl;
    cout<<"Ancho = "<<ancho<<endl;
    cout<<"Largo = "<<largo<<endl;
}
