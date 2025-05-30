#pragma once
#include "ConstructorListas.hpp"

class ConstructorJSON{
    private:
        vector<string> datos;

    public:
        //Constructor default
        ConstructorJSON()=default;
        
        //Agrego una linea (string) a sobre una lista de datos T que quiero guardar
        template<typename T>
        void addLine(const ConstructorListas<T>& lista){
            string linea;
            linea+="\""+lista.getTipo()+"\" : "+lista.procesar();
            datos.push_back(linea);
        }

        //Creo un string con el formato JSON requerido
        string createJSON()const{
            ostringstream os;
            os<<"{";
            for(auto line : datos){
                os<<"  "<<line<<"\n";
            }
            os<<"}"<<endl;
            return os.str();
        }

        //Imprimo el JSON en consola
        void imprimir()const{
            cout<<createJSON();
        }
};