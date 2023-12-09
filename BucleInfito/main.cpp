#include <iostream>

using namespace std;

int main()
{
    int x,y;
    while(true)
    {
        cout<<"Ingrese el valor de x"<<endl;
        cin>>x;
        cout<<"Ingrese el valor de y"<<endl;
        cin>>y;

        if(x<y)
        {
            //se ejecuta si la expresion es verdadera
            cout<<"x es menor que y"<<endl;
        }
        else
        {
            //se ejecuta si la expresion es falso
            cout<<"y es menor que x"<<endl;
        }
    }

    return 0;
}
