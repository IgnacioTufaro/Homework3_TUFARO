#pragma once
#include "I_mediciones.hpp"
using namespace std;

class MedicionBase : public IMediciones{
    protected:
        unique_ptr<float> Tmedicion;
    public:
        //Constructor default
        MedicionBase();
        //Constructor por parametro de inicializacion
        MedicionBase(float t);

        float get_tiempo()const;

        void serializar(ofstream& out)const override;
        void deserializar(ifstream& in)override;
        
        virtual void imprimir()const=0;
        virtual ~MedicionBase() = default;
};