#include <iostream>
#include <ctype.h>
using namespace std;

int main()
{
    string nombre = "Juan Perez";

    cout<<nombre[0]<<endl;
    cout<<nombre[1]<<endl;
    cout<<nombre[2]<<endl;
    cout<<nombre[3]<<endl;
    cout<<nombre[4]<<endl;
    cout<<nombre[5]<<endl;
    cout<<"--------------------------------"<<endl;
    for(int i=0;i<nombre.size();i++){
        cout<<nombre[i]<<endl;
    }
    cout<<"--------------------------------"<<endl;
    int i=0;
    while(nombre[i]!='\0'){
        cout<<nombre[i]<<endl;
        i++;
    }
    return 0;
}
