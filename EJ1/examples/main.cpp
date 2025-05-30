#include "../headers/C_posicion.hpp"
#include "../headers/C_presion.hpp"
#include "../headers/C_flightdata.hpp"

//g++ EJ1/src/*.cpp EJ1/examples/main.cpp -o EJ1/ex && EJ1/ex


int main(){
    Posicion posicion(-34.6f, -58.4f, 950.0f, 5.3f); 
    Presion presion(101.3f, 5.8f, 6.1f);
    SaveFlightData flight_data(posicion,presion);
    flight_data.imprimir();
    ofstream out("EJ1/logfiles/data.txt",ios::binary);
    if(out.is_open()){
        flight_data.serializar(out);
        out.close();
    }
    SaveFlightData flight_data_2;
    ifstream in("EJ1/logfiles/data.txt",ios::binary);
    if(in.is_open()){
        flight_data_2.deserializar(in);
        in.close();
    }
    flight_data_2.imprimir();

    return 0;
}