#include "../headers/C_presion.hpp"

//Constructor por parametros de inicializacion
Presion::Presion(float p, float q, float t):Pestatica(p),Pdinamica(q),MedicionBase(t){}
//Constructor por copia (deepcopy)
Presion::Presion(const Presion& other):Pestatica(other.Pestatica),Pdinamica(other.Pdinamica),MedicionBase(*other.Tmedicion){}

void Presion::serializar(ofstream& out) const{
    MedicionBase::serializar(out);
    out.write(reinterpret_cast<const char*>(&Pestatica),sizeof(float));
    out.write(reinterpret_cast<const char*>(&Pdinamica),sizeof(float));
}
void Presion::deserializar(ifstream& in){
    MedicionBase::deserializar(in);
    in.read(reinterpret_cast<char*>(&Pestatica),sizeof(float));
    in.read(reinterpret_cast<char*>(&Pdinamica),sizeof(float));
}
void Presion::imprimir()const{
    cout<<"===Presion==="<<endl;
    cout<<"Tiempo de medicion: "<<*Tmedicion<<endl;
    cout<<"Presion estática: "<<Pestatica<<endl;
    cout<<"Presion dinamica: "<<Pdinamica<<endl;
}