#pragma once
#include "punto.hpp"

using namespace std;

class Circulo{
    private:
        unique_ptr<Punto> centro;
        float radio;

    public:
        Circulo();
        Circulo(float x, float y, float r);
        Circulo(unique_ptr<Punto> c, float r);

        void setCentro(unique_ptr<Punto> c);
        void setCentro(float x, float y);
        void setRadio(float r);

        const Punto& getCentro() const;
        float getRadio() const;

        void imprimir()const;
};
