#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<type_traits>
#include <sstream>
using namespace std;

template<typename T>
class ConstructorListas{
    private:
        //Almaceno un vector de un tipo de dato generico (se especifica en la construccion del objeto)
        vector<T> datos;
    public:
        //Constructores
        ConstructorListas()=default;
        ConstructorListas(vector<T> datosIniciales):datos(datosIniciales){}
        
        //Agregar un valor de mi tipo T al vector de datos
        void add(const T& valor){
            if constexpr (is_same_v<T,double> || is_same_v<T,string> || is_same_v<T,vector<int>>){
                datos.push_back(valor);
            }
            else{"Tipo de dato no valido";}
        }

        //Genero un string de los datos almacenados
        string procesar() const{
            if(datos.empty()){return "Sin datos para procesar";}

            if constexpr(is_same_v<T,double>){
                ostringstream os;
                os<<"[";
                for(int i=0; i<datos.size();i++){
                    os<<datos[i];
                    if(i+1<datos.size()){os<<", ";}
                }
                os<<"]";
                return os.str();
            }
            else if constexpr(is_same_v<T,string>){
                ostringstream os;
                os<<"[";
                for(int i=0; i<datos.size();i++){
                    os<<"\""<<datos[i]<<"\"";
                    if(i+1<datos.size()){os<<", ";}
                }
                os<<"]";
                return os.str();
            }
            else if constexpr(is_same_v<T,vector<int>>){
                ostringstream os;
                os<<"[\n";
                for(auto vec : datos){
                    os<<"\t[";
                    for(int i=0; i<vec.size();i++){
                        os<<vec[i];
                        if(i+1 < vec.size()){os<<", ";}
                    }
                    os<<"]\n";
                }
                os<<"\t]";
                return os.str();
            }
            else {return "Vector invalido";}
        }

        //Devuelve el tipo de dato que se esta almacenando
        string getTipo() const{
            if constexpr (is_same_v<T,double>){return "Vec_doubles";}
            else if constexpr (is_same_v<T,string>){return "Palabras";}
            else if constexpr (is_same_v<T,vector<int>>){return "Listas";}
            else {return "Tipo no valido";}
        }
};
