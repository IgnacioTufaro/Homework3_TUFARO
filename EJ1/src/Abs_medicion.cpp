#include "../headers/Abs_medicion.hpp"

//Constructor default
MedicionBase::MedicionBase():Tmedicion(make_unique<float>(0.0f)){}
//Constructor por parametro de inicializacion
MedicionBase::MedicionBase(float t){Tmedicion = make_unique<float>(t);}

float MedicionBase::get_tiempo()const{return *Tmedicion;}

void MedicionBase::serializar(ofstream& out)const{
    out.write(reinterpret_cast<const char*>(Tmedicion.get()),sizeof(float)); 
}
void MedicionBase::deserializar(ifstream& in){
    in.read(reinterpret_cast<char*>(Tmedicion.get()),sizeof(float));
}

