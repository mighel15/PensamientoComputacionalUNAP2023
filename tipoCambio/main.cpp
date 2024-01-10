#include <iostream>

using namespace std;

#define TIPO_CAMBIO_SOLES_DOLARES 3.71
#define TIPO_CAMBIO_SOLES_EUROS 4.06

float solesADolares(float soles)
{
    return soles/TIPO_CAMBIO_SOLES_DOLARES;
}

float dolaresASoles(float dolares)
{
    return dolares*TIPO_CAMBIO_SOLES_DOLARES;
}

float solesAEuros(float soles)
{
    return soles/TIPO_CAMBIO_SOLES_EUROS;
}

float eurosASoles(float euros)
{
    return euros*TIPO_CAMBIO_SOLES_EUROS;
}

int main()
{
    //tengo 100 dolares, quiero cambiarlo a euros
    float soles, euros;
    soles = dolaresASoles(100);
    euros = solesAEuros(soles);

    cout<<"100 dolares es equivalente a "<<euros <<" euros"<<endl;


    return 0;
}
