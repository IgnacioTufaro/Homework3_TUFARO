#include"../headers/ConstructorJSON.hpp"
using namespace std;

//g++ EJ3/examples/main.cpp -o EJ3/ex && ./EJ3/ex

int main(){
    ConstructorListas<double> Ldoubles;
    ConstructorListas<string> Lstrings;
    ConstructorListas<vector<int>> LMints;

    Ldoubles.add(1.3);
    Ldoubles.add(2.1);
    Ldoubles.add(3.2);
    

    Lstrings.add("\033[4mHola \033[0m");
    Lstrings.add("Mundo");

    LMints.add(vector<int> {1,2});
    LMints.add(vector<int> {3,4});

    ConstructorJSON json;
    json.addLine(Ldoubles);
    json.addLine(Lstrings);
    json.addLine(LMints);

    json.imprimir();

    return 0;
}