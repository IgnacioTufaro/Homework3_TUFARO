#pragma once

#include<iostream>
#include <memory>
#include <utility>
#define PI 3.1415f
using namespace std;

class Punto{
    private:
        pair<float,float> punto;

    public:
        Punto();
        Punto(float x, float y);

        void setCoords(float x, float y);
        void setX(float x);
        void setY(float y);

        const pair<float, float> getCoords()const;
        float getX() const;
        float getY() const;
        
        void imprimir() const;
};

