#include <iostream>

using namespace std;

int factorial(int n)
{
    int resultado = 1;
    for(int i=n;i>0;i--)
    {
        resultado = resultado * i;
    }
    return resultado;

}
void recursivo(int n)
{
    if(n<=0)
        return;
    else
    {
        cout<<n<<endl;
        recursivo(n-1);
    }

}
int factorialrecursivo(int n)
{
    if(n<=0)
        return 1;
    else
        return n*factorialrecursivo(n-1);
}
int sumaNpares(int n)
{

    if(n<=0)
        return 0;
    else
    {
        cout<<n*2<<endl;
        return (n*2)+sumaNpares(n-1);
    }

}
int sumaNimpares(int n)
{

    if(n<=0)
        return 0;
    else
    {
        cout<<(n*2-1)<<endl;
        return (n*2-1)+sumaNpares(n-1);
    }

}

int main()
{
    cout<<sumaNpares(5)<<endl;
    cout<<sumaNpares(10)<<endl;
    cout<<factorialrecursivo(5)<<endl;
    cout<<factorialrecursivo(6)<<endl;
    return 0;
}
