#include <iostream>

using namespace std;

int main()
{
    int x,y;

    cout<<"Ingrese el valor de x"<<endl;
    cin>>x;
    cout<<"Ingrese el valor de y"<<endl;
    cin>>y;

    if(x<y)
    {
        //se ejecuta si la expresion if(x<y) es verdadera
        cout<<"x es menor que y"<<endl;
    }
    else
    {
        //se ejecuta si la expresion if(x<y) es falso
        if(x>y)
        {
            //se ejecuta si la expresion if(x>y) es verdadero
            cout<<"x es mayor que y"<<endl;
        }
        else
        {
            //se ejecuta si la expresion if(x>y) es false
            cout<<"x es igual que y"<<endl;
        }

    }
    return 0;
}
