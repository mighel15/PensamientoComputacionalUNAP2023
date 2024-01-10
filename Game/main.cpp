#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <list>
#include <mmsystem.h>
using namespace std;

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80

/* Ojo falta documentar :O*/
/* Ojo en propiedades - vinculador - entrada
   agregar winmm.lib para la musica
*/
void gotoxy(int x, int y)
{
	HANDLE hCon;
	//Recupera el control de la consola
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	//Son coodenadas
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
}

void ocultarCursor()
{
	HANDLE hCon;
	//Recupera el control de la consola
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 50;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hCon, &cci);
}
void pintarLimite()
{
	for (int i = 2; i < 78;i++)
	{
		gotoxy(i, 3); printf("%c", 205);
		gotoxy(i, 33); printf("%c", 205);
	}
	for (int i = 4; i < 33; i++)
	{
		gotoxy(2, i); printf("%c", 186);
		gotoxy(77, i); printf("%c", 186);
	}
	gotoxy(2, 3); printf("%c", 201);
	gotoxy(2, 33); printf("%c", 200);
	gotoxy(77, 3); printf("%c", 187);
	gotoxy(77, 33); printf("%c", 188);
}

void disparo()
{
	//sndPlaySound("snd_disparo.wav", SND_ASYNC);
}
void lose()
{
	//sndPlaySound("snd_lose.wav", SND_ASYNC);
}
void explosion()
{
	//sndPlaySound("explosion.wav", SND_ASYNC);

}

class NAVE
{
	int x, y;
	int corazones;
	int vidas;
public:
	NAVE();
	NAVE(int _x, int _y, int _corazones, int _vidas);
	void pintar();
	void borrar();
	void mover();
	void pintarCorazones();
	void perderVida();
	void dismunirCorazon(){ corazones--; }
	int X(){ return x; }
	int Y(){ return y; }
	int vidasJugador(){ return vidas; }

};
NAVE::NAVE(int _x, int _y, int _corazones,int _vidas)
{
	x = _x;
	y = _y;
	corazones = _corazones;
	vidas = _vidas;
}
void NAVE::pintar()
{
	gotoxy(x, y); printf("  %c", 30);
	gotoxy(x, y + 1); printf(" %c%c%c", 40, 207, 41);
	gotoxy(x, y + 2); printf("%c%c %c%c", 30, 190, 190, 30);

}
void NAVE::borrar()
{
	gotoxy(x, y);     printf("         ");
	gotoxy(x, y + 1); printf("         ");
	gotoxy(x, y + 2); printf("         ");
}
void NAVE::mover()
{
	if (_kbhit())
	{
		char tecla = _getch();
		borrar();
		if (tecla == IZQUIERDA && x > 3)
		{
			x--;
		}
		else if (tecla == DERECHA && x + 6 < 77)
		{
			x++;
		}
		else if (tecla == ARRIBA && y > 4 )
		{
			y--;
		}
		else if (tecla == ABAJO && y + 3 < 33  )
		{
			y++;
		}
		else if (tecla == 'e')
		{
			corazones--;
		}
		pintar();
		pintarCorazones();
	}
}
void NAVE::pintarCorazones()
{
	gotoxy(50, 2);
	printf("Vida: %d",vidas);
	gotoxy(64, 2);
	printf("Salud:");
	gotoxy(70, 2);
	printf("      ");
	for (int i = 0; i < corazones; i++)
	{
		gotoxy(70 + i, 2);
		printf("%c", 3);
	}
}
void NAVE::perderVida()
{
	if (corazones == 0)
	{
		borrar();
		gotoxy(x, y);     printf("   **   ");
		gotoxy(x, y + 1); printf("  ****  ");
		gotoxy(x, y + 2); printf("   **   ");
		Sleep(200);
		borrar();
		gotoxy(x, y);     printf(" * ** *");
		gotoxy(x, y + 1); printf("  **** ");
		gotoxy(x, y + 2); printf(" * ** *");
		Sleep(200);
		borrar();
		vidas--;
		corazones = 3;
		pintarCorazones();
		pintar();
		explosion();
	}
}
class Asteroide
{
	int x, y;
public:
	Asteroide(int _x, int _y);
	void pintar();
	void mover();
	void colisionNave(NAVE &nave);
	int X(){ return x; }
	int Y(){ return y; }
};
Asteroide::Asteroide(int _x, int _y)
{
	x = _x;
	y = _y;
}
void Asteroide::pintar()
{
	gotoxy(x, y); printf("%c", 184);
}
void Asteroide::mover()
{
	gotoxy(x, y); printf(" ");
	y++;
	if (y > 32)
	{
		x = (rand() % 71) + 4;
		y = 4;
	}
	pintar();
}
void Asteroide::colisionNave(NAVE &nave)
{
	if (x >= nave.X() && x < nave.X() + 6 && y >= nave.Y() && y <= nave.Y() + 2)
	{
		nave.dismunirCorazon();
		nave.borrar();
		nave.pintar();
		nave.pintarCorazones();
		x = (rand() % 71) + 4;
		y = 4;
	}
}
class Bala
{
	int x, y;
public:
	Bala(int _x, int _y);
	void mover();
	bool fuera();
	int X(){ return x; }
	int Y(){ return y; }
};
Bala::Bala(int _x, int _y)
{
	x = _x;
	y = _y;
}
void Bala::mover()
{
	gotoxy(x, y); printf(" ");
	y--;
	gotoxy(x, y); printf("*");

}
bool Bala::fuera()
{
	if (y == 4) return true;
	return false;

}

int main()
{
	ocultarCursor();
	pintarLimite();
	NAVE n(37,30,3,3);
	n.pintar();
	n.pintarCorazones();
	list<Asteroide*> A;
	list<Asteroide*>::iterator itA;
	int puntos = 0;
	for (int  i = 0; i < 5; i++)
	{
		A.push_back(new Asteroide(rand() % 75 + 3, rand() % 5 + 4));
	}
	list<Bala*> B;
	list<Bala*>::iterator it;
	bool gameOver = false;

	while (!gameOver)
	{

		gotoxy(4, 2); printf("Puntos: %d", puntos);
		if(_kbhit())
		{
			char tecla = _getch();
			if (tecla == 'a' || tecla == 'A')
			{
				B.push_back(new Bala(n.X() + 2, n.Y() - 1));
				disparo();
			}
		}
		//Disparo
		for (it = B.begin() ; it != B.end() ;)
		{
			(*it)->mover();
			if ((*it)->fuera())
			{

				gotoxy((*it)->X(), (*it)->Y()); printf(" ");
				delete(*it);
				it = B.erase(it);
			}
			else
			{
				it++;
			}
		}
		for (itA = A.begin(); itA != A.end(); itA++)
		{
			(*itA)->mover();
			(*itA)->colisionNave(n);
		}
		//Colision Bala - Asteroide
		for (itA = A.begin(); itA != A.end();itA++)
		{
			for (it = B.begin(); it != B.end();)
			{
				if ((*itA)->X() == (*it)->X() && ((*itA)->Y() + 1 == (*it)->Y() || (*itA)->Y() == (*it)->Y()))
				{
					gotoxy((*it)->X(), (*it)->Y()); printf(" ");
					delete(*it);
					it = B.erase(it);
					A.push_back(new Asteroide(rand() % 75 + 3, 4));
					gotoxy((*itA)->X(), (*itA)->Y()); printf(" ");
					delete(*itA);
					itA = A.erase(itA);
					puntos += 5;
				}
				else
				{
					it++;
				}
			}
		}
		if (n.vidasJugador() <= 0)
		{
			gameOver = true;
			lose();
			gotoxy(25, 18);
			printf("Game Over :(");

		}
		n.perderVida();
		n.mover();
		Sleep(30);
	}
	_getch();

	return 0;

}
