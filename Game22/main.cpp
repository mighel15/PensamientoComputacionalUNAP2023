#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <stdio.h>

class Comida{
   int xc,yc;                      // coordenadas de la comida
   public:
          Comida(int _x ,int _y);  // constructor
          void pintar_comida();
          int X() {return xc;}  // Interfaz
          int Y() {return yc;}
          void AsignaCoordenadas(int _x, int _y) {
            xc = _x;
            yc = _y;
          }// Asigna nuevas coordenadas a la comida.

};


void gotoxy(int x, int y)  {
    HANDLE hCon;
    COORD dwPos;

    dwPos.X = x;
    dwPos.Y = y;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon,dwPos);
}

void OcultaCursor() {
    CONSOLE_CURSOR_INFO cci = {100, FALSE}; // El segundo miembro de la estructura indica si se muestra el cursor o no.
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

void pintar(){
     // Líneas horizontales
     for(int i=2; i < 78; i++){
        gotoxy (i, 3); printf ("%c", 205);  // los números hacen referencia al código acsii
        gotoxy(i, 23); printf ("%c", 205);
     }
     //Líneas verticales
     for(int v=4; v < 23; v++){
        gotoxy (2,v);  printf ("%c", 186);
        gotoxy(77,v);  printf ("%c", 186);
     }
     // Esquinas
     gotoxy  (2,3);    printf ("%c", 201);
     gotoxy (2,23);    printf ("%c", 200);
     gotoxy (77,3);    printf ("%c", 187);
     gotoxy(77,23);    printf ("%c", 188);
}
int main()
{
    OcultaCursor();

    pintar();

    return 0;
}
