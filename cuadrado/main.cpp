#include <iostream>

using namespace std;

void dibujar_cuadrado(int tamanho)
{
    for(int i=0;i<tamanho;i++)
    {
        for(int j=0;j<tamanho-i;j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}

void dibujar_cuadrado_sp()
{
    int tamanho;
    cin>>tamanho;

    for(int i=0;i<tamanho;i++)
    {
        for(int j=0;j<tamanho-i;j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}

int main()
{
    /*int tamanho;
    cin>>tamanho;
    dibujar_cuadrado(tamanho);

    cin>>tamanho;
    dibujar_cuadrado(tamanho);

    cin>>tamanho;
    dibujar_cuadrado(tamanho);*/

    dibujar_cuadrado_sp();
    dibujar_cuadrado_sp();
    dibujar_cuadrado_sp();



    return 0;
}
