#include "../headers/C_posicion.hpp"

//Constructor por parametros de inicializacion
Posicion::Posicion(float lat,float lon,float alt,float t):MedicionBase(t),latitud(lat),longitud(lon),altitud(alt){}   
//Constructor por copia (deepcopy)
Posicion::Posicion(const Posicion& other):MedicionBase(*other.Tmedicion),latitud(other.latitud),longitud(other.longitud),altitud(other.altitud){}

void Posicion::serializar(ofstream& out)const{
    MedicionBase::serializar(out);
    out.write(reinterpret_cast<const char*>(&latitud),sizeof(float));
    out.write(reinterpret_cast<const char*>(&altitud),sizeof(float));
    out.write(reinterpret_cast<const char*>(&longitud),sizeof(float));
}
void Posicion::deserializar(ifstream& in){
    MedicionBase::deserializar(in);
    in.read(reinterpret_cast<char*>(&latitud),sizeof(float));
    in.read(reinterpret_cast<char*>(&altitud),sizeof(float));
    in.read(reinterpret_cast<char*>(&longitud),sizeof(float));
}
void Posicion::imprimir()const{
    cout<<"===Posicion==="<<endl;
    cout<<"Tiempo de medicion: "<<*Tmedicion<<endl;
    cout<<"Latitud: "<<latitud<<endl;
    cout<<"Altitud: "<<altitud<<endl;
    cout<<"Longitud: "<<longitud<<endl;
}