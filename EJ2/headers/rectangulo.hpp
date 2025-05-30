#pragma once
#include "punto.hpp"

using namespace std;

class Rectangulo{
    private: 
        unique_ptr<Punto> EsqIzq;
        float ancho;
        float largo;

    public:
        //Constructor default
        Rectangulo();
        //Constructores con parametros iniciales
        Rectangulo(float x,float y,float a,float l);
        Rectangulo(unique_ptr<Punto> esq, float a, float l);

        void setEsqIzq(unique_ptr<Punto> esq);
        void setEsqIzq(float x, float y);
        void setAncho(float a);
        void setLargo(float l);

        const Punto& getEsqIzq() const; 
        float getAncho() const;
        float getLargo() const;

        void imprimir() const;
};