#include <iostream>
using namespace std;

#define CONSOLE_HEIGHT 29
#define CONSOLE_WIDTH 119
//Inicializamos funciones
void ImprimirPantalla();
void RellenarMapa();
void Inputs();
void Start();
//Ahora vamos a crear lo que seria el mapa mediante una array bidimensional
char CosoleScreen[CONSOLE_HEIGHT][CONSOLE_WIDTH];
//Var del personaje
char personaje = '@';
int personaje_xPos = 10;
int personaje_yPos = 5;
bool run = true;


int main()
{

	Start();
	while (run)
	{
		Inputs();
		ImprimirPantalla();
	}
	cout << "El PacMan se va a cerrar" << endl;
}
void Start() {
	RellenarMapa();
	ImprimirPantalla();
}
void RellenarMapa()
{
	//Vamos a crear el marco del mapa
	for (int i = 0; i < CONSOLE_HEIGHT; i++)
	{
		for (int j = 0; j < CONSOLE_WIDTH; j++)
		{
			//Lo he puesto de dos maneras diferntes
			if (i == 0 || i == CONSOLE_HEIGHT - 1 || j == 0 || j == 118)
			{
				CosoleScreen[i][j] = '#';
			}
			else
			{
				CosoleScreen[i][j] = '-';
			}
		}

	}

}
void Inputs() {
	char input;
	cin >> input;
	switch (input)
	{
	case 'W':
	case'w':
		personaje_yPos--;
		break;
	case 'A':
	case'a':
		personaje_xPos--;
		break;
	case 'S':
	case's':
		personaje_yPos++;
		break;
	case 'D':
	case 'd':
		personaje_xPos++;
		break;
	case'Q':
	case'q':
		run = false;
		break;
	default:
		break;
	}
}
void ImprimirPantalla()
{
	for (int i = 0; i < CONSOLE_HEIGHT; i++)
	{
		for (int j = 0; j < CONSOLE_WIDTH; j++)
		{
			if (personaje_xPos == j && personaje_yPos == i)
			{
				cout << personaje;
			}
			else
			{
				cout << CosoleScreen[i][j];
			}
		}
		cout << endl;
	}
}
//Trabajo PacMan_JonDeLaCruz