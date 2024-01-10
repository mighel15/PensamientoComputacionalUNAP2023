#include <iostream>
#include <math.h>
using namespace std;
//funciones
float f(float x)
{
    //todo mi codigo para calcular la función
    float resultado=0;
    resultado = 3.1416 * pow(x,2);
    return resultado;
}
int main()
{
    float numero;
    cin>>numero;
    cout<<f(numero)<<endl;
    cout<<f(15)<<endl;
    cout<<f(20)<<endl;

    //cout << "Hello world!" << endl;
    return 0;
}
