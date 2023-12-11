#include <iostream>
#include <string.h>
using namespace std;

int main()
{

    //leer lineas con tipo de dato char
    char nombres[50];
    cout<<"Ingrese sus apellidos y nombres"<<endl;
    cin.getline(nombres,50);
    cout << "Hola mundo, yo soy " << nombres << endl;

    //leer lineas con tipo de dato string
    string nombres2;
    cout<<"Ingrese sus apellidos y nombres"<<endl;
    getline(cin,nombres2);
    cout << "Hola mundo, yo soy " << nombres2 << endl;

    //leer caracteres hasta encontrar un espacio o salto de linea
    string nombre3;
    cout<<"Ingrese sus apellidos y nombres"<<endl;
    cin>>nombre3;
    cout << "Hola mundo, yo soy " << nombre3 << endl;



    return 0;
}
