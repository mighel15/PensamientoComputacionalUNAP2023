#include <iostream>

using namespace std;

int main()
{
    float tallas[100];
    int cantidad;
    float promedio = 0;
    cin>>cantidad;
    for(int i=0;i<cantidad;i++)
    {
        cin>>tallas[i];
    }
    for(int i=0;i<cantidad;i++)
    {
        promedio += tallas[i];
    }
    for(int i=0;i<cantidad;i++)
    {
        cout<<tallas[i]<<" ";
    }
    cout<<endl;
    cout<<promedio/cantidad<<endl;
    return 0;
}
