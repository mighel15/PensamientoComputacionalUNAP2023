#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    //leer lineas con tipo de dato string
    string frase;
    cout<<"Ingrese sus apellidos y nombres"<<endl;
    getline(cin,frase);
    cout<<"La frase es: "<<frase<<endl;

    cout<<frase.size()<<endl;

    for(int i=0;i<frase.size();i++)
    {
        if(frase[i]=='a'||frase[i]=='A'||frase[i]=='e'||frase[i]=='E'||frase[i]=='i'||frase[i]=='I'||frase[i]=='o'||frase[i]=='O'||frase[i]=='u'||frase[i]=='U')
            cout<<frase[i]<<endl;
    }
    return 0;
}
