#include "../headers/C_flightdata.hpp"


//Como es agregacion tengo que copiar a nuevos objetos pos y p (Llamo a los constructores por copia de Posicion y Presion)
SaveFlightData::SaveFlightData(const Posicion& pos,const Presion& p):posicion(pos),presion(p){}

void SaveFlightData::serializar(ofstream& out)const{
    posicion.serializar(out);
    presion.serializar(out);
}
void SaveFlightData::deserializar(ifstream& in){
    posicion.deserializar(in);
    presion.deserializar(in);
}
void SaveFlightData::imprimir()const{
    posicion.imprimir();
    presion.imprimir();
}