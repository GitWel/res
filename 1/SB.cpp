#include "pch.h"
#include "SB.h"


void Pole::setCursorPosition(int x, int y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}

void Pole::menu() {
	setCursorPosition(3,5);
	cout << "Добро пожаловать в игру - Морской бой-1";
	setCursorPosition(3, 6);
	cout << "Перед началом игры рекомендуется ознакомиться с инструкцией.";
	setCursorPosition(3, 7);
	cout << "Нажмите F1, чтобы открыть инструкцию.";
	setCursorPosition(3, 24);
	cout << "Если хотите открыть информацию об авторе, нажмите F2";
	setCursorPosition(3, 12);
	cout << "Для продолжения нажмите любую клавишу.";
	int c;
	while (true) {
		c = _getch();
		if (c == 0) {
			c = _getch();
			if (c == 59) {
				system("Инструкция.txt");
			}
			else if (c == 60) {
				system("Автор.txt");
			}
		}
		else break;
	}
	system("cls");
}

void Pole::zap(int(&pole)[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			pole[i][j] = 0;
		}
	}
}

void Pole::zapoln(string(&pole)[11][11]) {
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
}

void Pole::vivod(string pole[11][11]) {
	setCursorPosition(5, 2);
	for (int i = 0; i < 11; i++) {
		setCursorPosition(5, 2 + i);
		for (int j = 0; j < 11; j++) {
			cout << " " << pole[i][j] << " ";
		}
	}
}

void Pole::clear(int(&pole)[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (pole[i][j] == 9)pole[i][j] = 0;
		}
	}
}

void Play::Sozd(int(&pole)[10][10], int z, int x, int y, int s, Ships *ships) {
	int n = 1, c = 0;
	ships[10 - k].health = z;
	a = 0;
	s = 0;
	int m[4] = { 0,0,0,0 };
	while (s == 0 && a != 4) {
		c = rand() % 4;
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
						ships[10 - k].l = z;
						ships[10 - k].x0 = x;
						ships[10 - k].y0 = y;
						ships[10 - k].x1 = x + z - 1;
						ships[10 - k].y1 = y;
						ships[10 - k].direc = 1;
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
						if (x - z >= 0) {
							pole[x - z][y] = 9;
							if (y - 1 >= 0)pole[x - z][y - 1] = 9;
							if (y + 1 <= 9)pole[x - z][y + 1] = 9;
						}
						s = 1;
						ships[10 - k].l = z;
						ships[10 - k].x0 = x;
						ships[10 - k].y0 = y;
						ships[10 - k].x1 = x - z + 1;
						ships[10 - k].y1 = y;
						ships[10 - k].direc = 2;
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
						ships[10 - k].l = z;
						ships[10 - k].x0 = x;
						ships[10 - k].y0 = y;
						ships[10 - k].x1 = x;
						ships[10 - k].y1 = y + z - 1;
						ships[10 - k].direc = 3;
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
						ships[10 - k].l = z;
						ships[10 - k].x0 = x;
						ships[10 - k].y0 = y;
						ships[10 - k].x1 = x;
						ships[10 - k].y1 = y - z + 1;
						ships[10 - k].direc = 4;
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
}
void Play::Chetire(int(&pole)[10][10]) {
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
	Sozd(pole, 4, x, y, s, ships);
	if (a == 4) {
		Chetire(pole);
	}
	k++;
};
void Play::Tri(int(&pole)[10][10]) {
	int s = 0, x, y;
	while (s != 1) {
		x = rand() % 10;
		y = rand() % 10;
		if (pole[x][y] == 0) {
			s = 1;
		}
	}
	Sozd(pole, 3, x, y, s, ships);
	if (a == 4) {
		Tri(pole);
	}
	k++;
};
void Play::Dva(int(&pole)[10][10]) {
	int s = 0, x, y;
	while (s != 1) {
		x = rand() % 10;
		y = rand() % 10;
		if (pole[x][y] == 0) {
			s = 1;
		}
	}
	Sozd(pole, 2, x, y, s, ships);
	if (a == 4) {
		Dva(pole);
	}
	k++;
};
void Play::Odin(int(&pole)[10][10]) {
	int s = 0, x, y;
	while (s != 1) {
		x = rand() % 10;
		y = rand() % 10;
		if (pole[x][y] == 0) {
			s = 1;
		}
	}
	Sozd(pole, 1, x, y, s, ships);
	if (a == 4) {
		Odin(pole);
	}
	k++;
};
void Play::death(int i) {
	switch (ships[i].direc) {
	case 1:
		if (ships[i].x0 - 1 >= 0) {
			setCursorPosition(9 + ships[i].y0 * 3, 3 + (ships[i].x0 - 1));
			cout << ".";
			if (ships[i].y0 - 1 >= 0) {
				setCursorPosition(9 + (ships[i].y0 - 1) * 3, 3 + (ships[i].x0 - 1));
				cout << ".";
			}
			if (ships[i].y0 + 1 <= 9) {
				setCursorPosition(9 + (ships[i].y0 + 1) * 3, 3 + (ships[i].x0 - 1));
				cout << ".";
			}
		};
		if (ships[i].x1 + 1 <= 9) {
			setCursorPosition(9 + (ships[i].y0) * 3, 3 + (ships[i].x1 + 1));
			cout << ".";
			if (ships[i].y0 - 1 >= 0) {
				setCursorPosition(9 + (ships[i].y0 - 1) * 3, 3 + (ships[i].x1 + 1));
				cout << ".";
			}
			if (ships[i].y0 + 1 <= 9) {
				setCursorPosition(9 + (ships[i].y0 + 1) * 3, 3 + (ships[i].x1 + 1));
				cout << ".";
			}
		}
		for (int p = 0; p < ships[i].l; p++) {
			if (ships[i].y0 - 1 >= 0) {
				setCursorPosition(9 + (ships[i].y0 - 1) * 3, 3 + (ships[i].x0 + p));
				cout << ".";
			}
			if (ships[i].y0 + 1 <= 9) {
				setCursorPosition(9 + (ships[i].y0 + 1) * 3, 3 + (ships[i].x0 + p));
				cout << ".";
			}
		}
		setCursorPosition(5, 17);
		cout << "                                                  ";
		setCursorPosition(5, 17);
		cout << "Убит!";
		break;
	case 2:
		if (ships[i].x0 + 1 <= 9) {
			setCursorPosition(9 + ships[i].y0 * 3, 3 + (ships[i].x0 + 1));
			cout << ".";
			if (ships[i].y0 - 1 >= 0) {
				setCursorPosition(9 + (ships[i].y0 - 1) * 3, 3 + (ships[i].x0 + 1));
				cout << ".";
			}
			if (ships[i].y0 + 1 <= 9) {
				setCursorPosition(9 + (ships[i].y0 + 1) * 3, 3 + (ships[i].x0 + 1));
				cout << ".";
			}
		};
		if (ships[i].x1 - 1 >= 0) {
			setCursorPosition(9 + (ships[i].y0) * 3, 3 + (ships[i].x1 - 1));
			cout << ".";
			if (ships[i].y0 - 1 >= 0) {
				setCursorPosition(9 + (ships[i].y0 - 1) * 3, 3 + (ships[i].x1 - 1));
				cout << ".";
			}
			if (ships[i].y0 + 1 <= 9) {
				setCursorPosition(9 + (ships[i].y0 + 1) * 3, 3 + (ships[i].x1 - 1));
				cout << ".";
			}
		}
		for (int p = 0; p < ships[i].l; p++) {
			if (ships[i].y0 - 1 >= 0) {
				setCursorPosition(9 + (ships[i].y0 - 1) * 3, 3 + (ships[i].x0 - p));
				cout << ".";
			}
			if (ships[i].y0 + 1 <= 9) {
				setCursorPosition(9 + (ships[i].y0 + 1) * 3, 3 + (ships[i].x0 - p));
				cout << ".";
			}
		}
		setCursorPosition(5, 17);
		cout << "                                                  ";
		setCursorPosition(5, 17);
		cout << "Убит!";
		break;
	case 3:
		if (ships[i].y0 - 1 >= 0) {
			setCursorPosition(9 + (ships[i].y0 - 1) * 3, 3 + (ships[i].x0));
			cout << ".";
			if (ships[i].x0 - 1 >= 0) {
				setCursorPosition(9 + (ships[i].y0 - 1) * 3, 3 + (ships[i].x0 - 1));
				cout << ".";
			}
			if (ships[i].x0 + 1 <= 9) {
				setCursorPosition(9 + (ships[i].y0 - 1) * 3, 3 + (ships[i].x0 + 1));
				cout << ".";
			}
		};
		if (ships[i].y1 + 1 <= 9) {
			setCursorPosition(9 + (ships[i].y1 + 1) * 3, 3 + (ships[i].x1));
			cout << ".";
			if (ships[i].x0 - 1 >= 0) {
				setCursorPosition(9 + (ships[i].y1 + 1) * 3, 3 + (ships[i].x0 - 1));
				cout << ".";
			}
			if (ships[i].x0 + 1 <= 9) {
				setCursorPosition(9 + (ships[i].y1 + 1) * 3, 3 + (ships[i].x0 + 1));
				cout << ".";
			}
		}
		for (int p = 0; p < ships[i].l; p++) {
			if (ships[i].x0 - 1 >= 0) {
				setCursorPosition(9 + (ships[i].y0 + p) * 3, 3 + (ships[i].x0 - 1));
				cout << ".";
			}
			if (ships[i].x0 + 1 <= 9) {
				setCursorPosition(9 + (ships[i].y0 + p) * 3, 3 + (ships[i].x0 + 1));
				cout << ".";
			}
		}
		setCursorPosition(5, 17);
		cout << "                                                  ";
		setCursorPosition(5, 17);
		cout << "Убит!";
		break;
	case 4:
		if (ships[i].y0 + 1 <= 9) {
			setCursorPosition(9 + (ships[i].y0 + 1) * 3, 3 + (ships[i].x0));
			cout << ".";
			if (ships[i].x0 - 1 >= 0) {
				setCursorPosition(9 + (ships[i].y0 + 1) * 3, 3 + (ships[i].x0 - 1));
				cout << ".";
			}
			if (ships[i].x0 + 1 <= 9) {
				setCursorPosition(9 + (ships[i].y0 + 1) * 3, 3 + (ships[i].x0 + 1));
				cout << ".";
			}
		};
		if (ships[i].y1 - 1 >= 0) {
			setCursorPosition(9 + (ships[i].y1 - 1) * 3, 3 + (ships[i].x1));
			cout << ".";
			if (ships[i].x0 - 1 >= 0) {
				setCursorPosition(9 + (ships[i].y1 - 1) * 3, 3 + (ships[i].x0 - 1));
				cout << ".";
			}
			if (ships[i].x0 + 1 <= 9) {
				setCursorPosition(9 + (ships[i].y1 - 1) * 3, 3 + (ships[i].x0 + 1));
				cout << ".";
			}
		}
		for (int p = 0; p < ships[i].l; p++) {
			if (ships[i].x0 - 1 >= 0) {
				setCursorPosition(9 + (ships[i].y0 - p) * 3, 3 + (ships[i].x0 - 1));
				cout << ".";
			}
			if (ships[i].x0 + 1 <= 9) {
				setCursorPosition(9 + (ships[i].y0 - p) * 3, 3 + (ships[i].x0 + 1));
				cout << ".";
			}
		}
		setCursorPosition(5, 17);
		cout << "                                                  ";
		setCursorPosition(5, 17);
		cout << "Убит!";
		break;
	}
}
void Play::check(int(&pole)[10][10]) {
	for (int i = 0; i < 10; i++) {
		switch (ships[i].direc) {
		case 1:
			for (int j = 0; j < ships[i].l; j++) {
				if (pole[ships[i].x0 + j][ships[i].y0] == 7) {
					ships[i].health--;
					pole[ships[i].x0 + j][ships[i].y0] = 8;
					if (ships[i].health == 0)death(i);
				}
			};
			break;
		case 2:
			for (int j = 0; j < ships[i].l; j++) {
				if (pole[ships[i].x0 - j][ships[i].y0] == 7) {
					ships[i].health--;
					pole[ships[i].x0 - j][ships[i].y0] = 8;
					if (ships[i].health == 0)death(i);
				}
			};
			break;
		case 3:
			for (int j = 0; j < ships[i].l; j++) {
				if (pole[ships[i].x0][ships[i].y0 + j] == 7) {
					ships[i].health--;
					pole[ships[i].x0][ships[i].y0 + j] = 8;
					if (ships[i].health == 0)death(i);
				}
			};
			break;
		case 4:
			for (int j = 0; j < ships[i].l; j++) {
				if (pole[ships[i].x0][ships[i].y0 - j] == 7) {
					ships[i].health--;
					pole[ships[i].x0][ships[i].y0 - j] = 8;
					if (ships[i].health == 0)death(i);
				}
			};
			break;

		}
	}
}

void Play::Xod(int(&pole)[10][10]) {
	int z = 0;
	string cord;
	while (z != 20) {
		setCursorPosition(5, 15);
		cout << "Введите координаты(Пример-Г7): ";
		cin >> cord;
		if ((int)cord[0] <= -54 && (int)cord[0] >= -64 && (int)cord[0] != -53 && cord.length() <= 3 && (48 < cord[1] && cord[1] < 58)) {
			if ((cord.length() == 3 && cord[1] == 49 && cord[2] == 48) || (cord.length() == 2)) {
				if (cord[1] == 49 && cord[2] == 48)cord[1] = 58;
				if ((int)cord[0] == -54)cord[0] = 201;
				if (pole[(int)cord[0] + 64][cord[1] - 49] != 7 && pole[(int)cord[0] + 64][cord[1] - 49] != 8) {
					if (pole[(int)cord[0] + 64][cord[1] - 49] != 0) {
						pole[(int)cord[0] + 64][cord[1] - 49] = 7;
						setCursorPosition(5, 17);
						cout << "Ранил!";
						setCursorPosition(9 + (cord[1] - 49) * 3, 3 + (int)cord[0] + 64);
						cout << "x";
						z++;
						check(pole);
					}
					else {
						pole[(int)cord[0] + 64][cord[1] - 49] = 7;
						setCursorPosition(9 + (cord[1] - 49) * 3, 3 + (int)cord[0] + 64);
						cout << ".";
						setCursorPosition(5, 17);
						cout << "Мимо!";
					}
				}
				else {
					setCursorPosition(5, 17);
					cout << "Вы уже производили атаку по этим координатам";
				}
				Sleep(2000);
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
	cout << "Все вражеские корабли уничтожены";
	Sleep(2000);
	system("cls");
	setCursorPosition(10, 10);
	cout << "Вы победили!!!";
}