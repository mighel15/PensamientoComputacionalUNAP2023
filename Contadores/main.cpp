#include <iostream>

using namespace std;

int main()
{
    int contador = 0;
    cout<<"el valor del contador es = "<<contador<<endl;

    contador = contador + 1;
    cout<<"el valor del contador es = "<<contador<<endl;

    contador += 1;
    cout<<"el valor del contador es = "<<contador<<endl;

    contador++;
    cout<<"el valor del contador es = "<<contador<<endl;

    contador = contador + 1;
    contador += 1;
    contador++;//incrementador

    contador = contador - 1;
    contador -= 1;
    contador --;//decrementador
    cout<<"el valor del contador es = "<<contador<<endl;
    return 0;
}
