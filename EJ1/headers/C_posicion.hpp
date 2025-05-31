#pragma once
#include "Abs_medicion.hpp"
using namespace std;

class Posicion : public MedicionBase{
    public:
        //Atributos publicos
        float latitud;
        float longitud;
        float altitud;
        
        //Constructor default
        Posicion() = default;
        //Constructor por parametros de inicializacion
        Posicion(float lat,float lon,float alt,float t);  
        //Constructor por copia (deepcopy)
        Posicion(const Posicion& other);

        void serializar(ofstream& out)const override;
        void deserializar(ifstream& in)override;

        void imprimir()const override;
};