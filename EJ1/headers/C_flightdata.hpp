#pragma once
#include "C_presion.hpp"
#include "C_posicion.hpp"
using namespace std;

class SaveFlightData {
    public:
        Posicion posicion;
        Presion presion;
        //Constructor default
        SaveFlightData() = default;
        //Como es agregacion tengo que copiar a nuevos objetos pos y p
        SaveFlightData(const Posicion& pos,const Presion& p);

        void serializar(ofstream& out)const;
        void deserializar(ifstream& in);

        void imprimir()const;
};
