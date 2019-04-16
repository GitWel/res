#include "pch.h"
#include <iostream>
#include <ctime>
#include <windows.h>
#include <string>
#include <conio.h>

using namespace std;

const int NotUsed = system("color 3");

class Ships {
public:
	int x0;
	int y0;
	int x;
	int y;
};

class CreateShips {
public:
	int o = 0;
	int a = 0;
	int **Sozd(int** pole, int z, int x, int y, int s) {
		int n = 1, c = 0;
		a = 0;
		s = 0;
		int m[4] = { 0,0,0,0 };
		while (s == 0 && a != 4) {
			c = rand() % 4;
			//c = 3;
			if (m[c] == -1) {
				while (m[c] == -1)c = rand() % 4;
			}
			switch (c)
			{
			case 0:
				if (x + z <= 9) {
					if (pole[x + z][y] == 0 || pole[x + z][y] == 9) {
						for (int i = 1; i < z; i++) {
							if (pole[x + i][y] == 0)n++;
						}
						if (n == z) {
							for (int i = 0; i < z; i++) {
								pole[x + i][y] = z;
								if (y + 1 <= 9)pole[x + i][y + 1] = 9;
								if (y - 1 >= 0)pole[x + i][y - 1] = 9;
							}
							if (x - 1 >= 0) {
								pole[x - 1][y] = 9;
								if (y - 1 >= 0)pole[x - 1][y - 1] = 9;
								if (y + 1 <= 9)pole[x - 1][y + 1] = 9;
							}
							if (x + z <= 9) {
								pole[x + z][y] = 9;
								if (y - 1 >= 0)pole[x + z][y - 1] = 9;
								if (y + 1 <= 9)pole[x + z][y + 1] = 9;
							}
							s = 1;
						}
						else {
							m[0] = -1;
							a++;
						}
					}
					else {
						m[0] = -1;
						a++;
					}
				}
				else {
					m[0] = -1;
					a++;
				}
				break;
			case 1:
				if (x - z >= 0) {
					if (pole[x - z][y] == 0 || pole[x - z][y] == 9) {
						for (int i = 1; i < z; i++) {
							if (pole[x - i][y] == 0)n++;
						}
						if (n == z) {
							for (int i = 0; i < z; i++) {
								pole[x - i][y] = z;
								if (y + 1 <= 9)pole[x - i][y + 1] = 9;
								if (y - 1 >= 0)pole[x - i][y - 1] = 9;
							}
							if (x + 1 <= 9) {
								pole[x + 1][y] = 9;
								if (y - 1 >= 0)pole[x + 1][y - 1] = 9;
								if (y + 1 <= 9)pole[x + 1][y + 1] = 9;
							}
							if (x - z >=0) {
								pole[x - z][y] = 9;
								if (y - 1 >= 0)pole[x - z][y - 1] = 9;
								if (y + 1 <= 9)pole[x - z][y + 1] = 9;
							}
							s = 1;
						}
						else {
							m[1] = -1;
							a++;
						}

					}
					else {
						m[1] = -1;
						a++;
					}
				}
				else {
					m[1] = -1;
					a++;
				}
				break;
			case 2:
				if (y + z <= 9) {
					if (pole[x][y + z] == 0 || pole[x][y + z] == 9) {
						for (int i = 1; i < z; i++) {
							if (pole[x][y + i] == 0)n++;
						}
						if (n == z) {
							for (int i = 0; i < z; i++) {
								pole[x][y + i] = z;
								if (x + 1 <= 9)pole[x + 1][y + i] = 9;
								if (x - 1 >= 0)pole[x - 1][y + i] = 9;
							}
							if (y - 1 >= 0) {
								pole[x][y - 1] = 9;
								if (x - 1 >= 0)pole[x - 1][y - 1] = 9;
								if (x + 1 <= 9)pole[x + 1][y - 1] = 9;
							}
							if (y + z <= 9) {
								pole[x][y + z] = 9;
								if (x - 1 >= 0)pole[x - 1][y + z] = 9;
								if (x + 1 <= 9)pole[x + 1][y + z] = 9;
							}
							s = 1;
						}
						else {
							m[2] = -1;
							a++;
						}
					}
					else {
						m[2] = -1;
						a++;
					}
				}
				else {
					m[2] = -1;
					a++;
				}
				break;
			case 3:
				if (y - z >= 0) {
					if (pole[x][y - z] == 0 || pole[x][y - z] == 9) {
						for (int i = 1; i < z; i++) {
							if (pole[x][y - i] == 0)n++;
						}
						if (n == z) {
							for (int i = 0; i < z; i++) {
								pole[x][y - i] = z;
								if (x + 1 <= 9)pole[x + 1][y - i] = 9;
								if (x - 1 >= 0)pole[x - 1][y - i] = 9;
							}
							if (y + 1 <= 9) {
								pole[x][y + 1] = 9;
								if (x - 1 >= 0)pole[x - 1][y + 1] = 9;
								if (x + 1 <= 9)pole[x + 1][y + 1] = 9;
							}
							if (y - z >= 0) {
								pole[x][y - z] = 9;
								if (x - 1 >= 0)pole[x - 1][y - z] = 9;
								if (x + 1 <= 9)pole[x + 1][y - z] = 9;
							}
							s = 1;
						}
						else {
							m[3] = -1;
							a++;
						}

					}
					else {
						m[3] = -1;
						a++;
					}
				}
				else {
					m[3] = -1;
					a++;
				}
				break;
			}
		}
		return pole;
	}
	int **Chetire(int **pole) {
		int s = 0;
		int x;
		int y;
		while (s != 1) {
			x = rand() % 10;
			y = rand() % 10;
			if (pole[x][y] == 0) {
				s = 1;
			}
		}
		Sozd(pole, 4, x, y, s);
		if (a == 4) {
			Chetire(pole);
		}
		return pole;
	};
	int **Tri(int **pole) {
		int s = 0, x, y;
		while (s != 1) {
			x = rand() % 10;
			y = rand() % 10;
			if (pole[x][y] == 0) {
				s = 1;
			}
		}
		Sozd(pole, 3, x, y, s);
		if (a == 4) {
			Tri(pole);
		}
		return pole;
	};
	int **Dva(int **pole) {
		int s = 0, x, y;
		while (s != 1) {
			x = rand() % 10;
			y = rand() % 10;
			if (pole[x][y] == 0) {
				s = 1;
			}
		}
		Sozd(pole, 2, x, y, s);
		if (a == 4) {
			Dva(pole);
		}
		return pole;
	};
	int **Odin(int **pole) {
		int s = 0, x, y;
		while (s != 1) {
			x = rand() % 10;
			y = rand() % 10;
			if (pole[x][y] == 0) {
				s = 1;
			}
		}
		Sozd(pole, 1, x, y, s);
		if (a == 4) {
			Odin(pole);
		}
		return pole;
	};
};

class Pole {
public:

	int **sozd(int **pole) {
		for (int i = 0; i < 10; i++) {
			pole[i] = new int[10];
		}
		return pole;
	}
	string **soz(string **pole) {
		for (int i = 0; i < 11; i++) {
			pole[i] = new string[11];
		}
		return pole;
	}
	int **zap(int **pole) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				pole[i][j] = 0;
			}
		}
		return pole;
	}
	string **zapoln(string **pole) {
		pole[0][0] = " ";
		for (int i = 1; i < 11; i++) {
			for (int j = 1; j < 11; j++) {
				pole[i][j] = "o";
			}
		}
		for (int i = 1; i < 11; i++) {
			if (49 + i > 58) {
				pole[0][i] = "10";
			}
			else {
				pole[0][i] = 48 + i;
			}
		}
		for (int j = 1; j < 11; j++) {
			if (191 + j == 201) { pole[j][0] = 202; }
			else { pole[j][0] = 191 + j; }
		}
		return pole;
	}
	void viv(int **array) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cout << " " << array[i][j] << " ";
			}
			cout << endl;
		}
	}

	int **clear(int **pole) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (pole[i][j] == 9)pole[i][j] = 0;
			}
		}
		return pole;
	}

};

class Play {
public:
	void setCursorPosition(int x, int y)
	{
		static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		cout.flush();
		COORD coord = { (SHORT)x, (SHORT)y };
		SetConsoleCursorPosition(hOut, coord);
	}
	void vivod(string **array) {
		setCursorPosition(5, 2);
		for (int i = 0; i < 11; i++) {
			setCursorPosition(5, 2 + i);
			for (int j = 0; j < 11; j++) {
				cout << " " << array[i][j] << " ";
			}
		}
	}
	void Xod(int **pole) {
		int z = 0;
		string cord;
		while (z != 20) {
			setCursorPosition(5, 15);
			cout << "Введите координаты(Пример-Г7): ";
			cin >> cord;
			if ((int)cord[0] <= -54 && (int)cord[0] >= -64 && (int)cord[0] != -53 && cord.length() <= 3 && (48 < cord[1] && cord[1] < 57)) {
				if ((cord.length() == 3 && cord[1] == 49 && cord[2] == 48) || (cord.length() == 2)) {
					if (cord[1] == 49 && cord[2] == 48)cord[1] = 58;
					if ((int)cord[0] == -54)cord[0] = 201;
					if (pole[(int)cord[0] + 64][cord[1] - 49] != 7) {
						if (pole[(int)cord[0] + 64][cord[1] - 49] != 0) {
							pole[(int)cord[0] + 64][cord[1] - 49] = 7;
							setCursorPosition(5, 17);
							cout << "Попадание";
							setCursorPosition(9 + (cord[1] - 49) * 3, 3 + (int)cord[0] + 64);
							cout << "x";
							z++;
						}
						else {
							pole[(int)cord[0] + 64][cord[1] - 49] = 7;
							setCursorPosition(9 + (cord[1] - 49) * 3, 3 + (int)cord[0] + 64);
							cout << ".";
							setCursorPosition(5, 17);
							cout << "Промах";
						}
					}
					else {
						setCursorPosition(5, 17);
						cout << "Вы уже производили атаку по этим координатам";
					}
					Sleep(1000);
					setCursorPosition(5, 15);
					cout << "                                                  ";
					setCursorPosition(5, 17);
					cout << "                                                  ";
				}
				else {
					setCursorPosition(5, 17);
					cout << "Вы ввели неверные координаты";
					Sleep(1000);
					setCursorPosition(5, 15);
					cout << "                                                  ";
					setCursorPosition(5, 17);
					cout << "                                                  ";
				}
			}
			else {
				setCursorPosition(5, 17);
				cout << "Вы ввели неверные координаты";
				Sleep(1000);
				setCursorPosition(5, 15);
				cout << "                                                  ";
				setCursorPosition(5, 17);
				cout << "                                                  ";
			}
		}
		setCursorPosition(5, 17);
		cout << "Все вражеские корабли унечтожены";
		Sleep(2000);
		system("cls");
		setCursorPosition(10, 10);
		cout << "Вы победили ";
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	Pole Pole; // Создание
	CreateShips CrShips; // Создание
	Play Play;
	string **pole = new string*[11]; // Создание
	int **polecom = new int*[10];
	Pole.soz(pole);
	Pole.zapoln(pole);
	Play.vivod(pole);
	Pole.sozd(polecom);
	Pole.zap(polecom);
	CrShips.Chetire(polecom);
	for (int i = 0; i < 2; i++)CrShips.Tri(polecom);
	for (int i = 0; i < 3; i++)CrShips.Dva(polecom);
	for (int i = 0; i < 4; i++)CrShips.Odin(polecom);
	Pole.clear(polecom);
	Play.setCursorPosition(0, 20);
	Pole.viv(polecom);
	Play.Xod(polecom);
	system("pause>>NULL");
}