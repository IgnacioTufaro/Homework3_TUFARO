#pragma once
#include "Abs_medicion.hpp"
using namespace std;

class Presion : public MedicionBase{
    public:
        float Pestatica;
        float Pdinamica;
        //Constructor default
        Presion() = default;
        //Constructor por parametros de inicializacion
        Presion(float p, float q, float t);
        //Constructor por copia (deepcopy)
        Presion(const Presion& other);

        void serializar(ofstream& out) const override;
        void deserializar(ifstream& in)override;

        void imprimir()const override;
};