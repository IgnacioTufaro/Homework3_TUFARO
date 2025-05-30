#pragma once
#include "circulo.hpp"
#include "elipse.hpp"
#include "rectangulo.hpp"

using namespace std;

template<typename T>
class ProcesadorFigura{
    public:
        static string area(T t){return "Figura no valida";}
};
//Solo quiero usar el metodo de la funcion sin instanciarla ==> los defino como static
template<>
class ProcesadorFigura<Circulo>{
    public:
        static float area(const Circulo& c){return (PI * c.getRadio() * c.getRadio());}
};

template<>
class ProcesadorFigura<Elipse>{
    public:
        static float area(const Elipse& e){return (PI * e.getSemiEjeMayor() * e.getSemiEjeMenor());}
};

template<>
class ProcesadorFigura<Rectangulo>{
    public:
        static float area(const Rectangulo& r){return (r.getAncho() * r.getLargo());}
};
