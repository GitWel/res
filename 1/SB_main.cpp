#include "pch.h"
#include "SB.h"
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	system("mode con cols=65 lines=25");
	system("title Морской бой-1");
	srand(time(NULL));
	Pole Pole;
	Play Play;
	Pole.menu();
	string pole[11][11];
	int polecom[10][10];
	Pole.zapoln(pole);
	Pole.vivod(pole);
	Pole.zap(polecom);
	Play.Chetire(polecom);
	for (int i = 0; i < 2; i++)Play.Tri(polecom);
	for (int i = 0; i < 3; i++)Play.Dva(polecom);
	for (int i = 0; i < 4; i++)Play.Odin(polecom);
	Pole.clear(polecom);
	Play.Xod(polecom);
	system("pause>>NULL");
}