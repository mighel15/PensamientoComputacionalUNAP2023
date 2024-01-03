#include <iostream>

using namespace std;

int main()
{
    int scores[10]={123,0,321,50,40,60,70,80,12,13};
    int suma = 0;
    for(int i=0;i<10;i++)
    {
        scores[i]= i+100;
        cout<<"scores["<<i<<"]->"<<scores[i]<<endl;
    }
    for(int i=0;i<10;i++)
    {
        suma += scores[i];
    }
    cout<<"La suma de scores es:  "<<suma<<endl;
    return 0;
}
