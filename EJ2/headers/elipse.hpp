#pragma once 
#include "punto.hpp"

using namespace std;

class Elipse{
    private:
        unique_ptr<Punto> centro;
        pair<float,float> semi_ejes;
    
    public:
        //Constructor default, inicializa en 0.0
        Elipse();
        //Constructor por parametros
        Elipse(float x, float y, float a, float b);
        Elipse(unique_ptr<Punto> c, float a, float b);

        void setCentro(unique_ptr<Punto> c);
        void setCentro(float x, float y);
        void setSemiEjeMayor(float a);
        void setSemiEjeMenor(float b);

        const Punto& getCentro() const;
        float getSemiEjeMayor() const;
        float getSemiEjeMenor() const;

        void imprimir()const;
};