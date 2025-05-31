#include "../headers/ProcesadorFigura.hpp"

//g++ EJ2/src/*.cpp EJ2/examples/main.cpp -o EJ2/ex && EJ2/ex

int main() {
    //Prueba de Punto
    cout<<"=== Puntos ==="<<endl;
    Punto p1; //Constructor default             
    Punto p2(2.5f, -2.5f);   //Constructor con parametros iniciales         

    cout<<"Punto p1 constructor default: ";
    p1.imprimir();
    cout<<"Punto p2 incializado en (2.5, -2.5): ";
    p2.imprimir();

    p1.setCoords(1.0f, -1.0f); //Prueba setear valores del punto
    p2.setX(5.0f);
    p2.setY(0.5f);
    cout<<"Punto p1 tras setCoords(1, -1): "<<endl;
    p1.imprimir();
    cout<<"Punto p2 tras setX(5) y setY(0.5): "<<endl;
    p2.imprimir();

    //Prueba de Círculo
    cout<<"\n=== Círculos ==="<<endl;
    Circulo c1;                     //Constructor default
    Circulo c2(-5.5f, 0.5f, 4.5f);   //Constructor con valores iniciales
    unique_ptr<Punto> pc = make_unique<Punto>(1.0f, -1.0f);
    Circulo c3(move(pc), 2.0f);     //Constructor inicializado con punto y radio

    
    cout<<"\nCirculo c1 (default): "<<endl;
    c1.imprimir();
    cout<<"\nCirculo c2 con valores iniciales (-5.5, 0.5, R=4.5): "<<endl;
    c2.imprimir();
    cout<<"\nCirculo c3 con centro ya creado (p1, R=2): "<<endl;
    c3.imprimir();

    c1.setCentro(1.1f, -1.1f); //pruebo setear valores
    c1.setRadio(3.3f);
    cout<<"\nCirculo c1 tras setCentro(1.1,1.1) y setRadio(3.3): "<<endl;
    c1.imprimir();

    //Prueba calcular el area
    cout<< "\n~Área c1~"<<endl; 
    cout<<"Esperado: "<<PI*c1.getRadio()*c1.getRadio()<<endl;
    cout<<"Obtenido: "<<ProcesadorFigura<Circulo>::area(c1)<<endl;


    //Prueba de Elipse
    cout << "\n\n=== Elipses ==="<<endl;
    Elipse e1;                          //constructor default
    Elipse e2(-5.0f, 2.0f, 2.5f, 4.0f);  //Constructor con valores iniciales
    unique_ptr<Punto> pe = make_unique<Punto>(1.0f, -1.0f);
    Elipse e3(move(pe), 5.0f, 3.0f);    //constructor inicializando con punto y semiejes

    cout<<"\nElipse e1 (default): "<<endl;
    e1.imprimir();
    cout<<"\nElipse e2 con valores iniciales: "<<endl;
    e2.imprimir();
    cout<<"\nElipse e3 con centro ya creado: "<<endl;
    e3.imprimir();

    e1.setCentro(-0.5f, 0.5f); //Pruebo setear valores
    e1.setSemiEjeMayor(5.0f);
    e1.setSemiEjeMenor(2.0f);
    cout<<"\nElipse e1 tras setters setear centro en (-0.5, 0.5) y semi ejes de (5, 2): "<<endl;
    e1.imprimir();

    //Prueba calcular el area
    cout<<"\n~Área e1~"<<endl;
    cout<<"Esperado: "<<PI*e1.getSemiEjeMayor()*e1.getSemiEjeMenor()<<endl;
    cout<<"Obtenido: "<<ProcesadorFigura<Elipse>::area(e1)<<endl;


    //Prueba de Rectángulo
    cout<<"\n\n=== Rectángulos ==="<<endl;
    Rectangulo r1;                              //constructor default
    Rectangulo r2(-2.5f, 3.0f, 4.0f, 2.0f);      //Constructor con valores iniciales
    unique_ptr<Punto> pr = make_unique<Punto>(1.0f, -1.0f);
    Rectangulo r3(move(pr), 6.0f, 3.0f);        //constructor con punto y lados

    cout<<"\nRectangulo r1 (default): "<<endl;
    r1.imprimir();
    cout<<"\nRectangulo r2 con valores iniciales: "<<endl;
    r2.imprimir();
    cout<<"\nRectangulo r3 con centro ya creado: "<<endl;
    r3.imprimir();

    unique_ptr<Punto> pr2 = make_unique<Punto>(2.0f,-2.0f);
    r1.setEsqIzq(move(pr2)); //pruebo los setters
    r1.setAncho(6.5f);
    r1.setLargo(10.0f);
    cout<<"\nRectangulo r1 tras setear centro en (2,-2) y lados de (6.5, 10): "<<endl;
    r1.imprimir();

    //Prueba calcular el area
    cout<<"\n~Área r1~"<<endl;
    cout<<"Esperado: "<<r1.getAncho() * r1.getLargo()<<endl;
    cout<<"Obtenido: "<<ProcesadorFigura<Rectangulo>::area(r1)<<endl;


    //Prueba de casos extremos
    cout<<"\n===Prueba de excepciones==="<<endl;
    cout<<"Intentar procesar una figura no valida"<<endl;
    float t=5;
    cout<<ProcesadorFigura<float>::area(t)<<endl;
    

    return 0;
}