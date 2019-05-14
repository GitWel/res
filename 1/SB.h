#pragma once

#ifndef SB_H
#define SB_H
#include <iostream>
#include <ctime>
#include <windows.h>
#include <string>
#include <conio.h>
using namespace std;

const int NotUsed = system("color 3");

class Ships {
public:
	int health;
	int x0, y0, x1, y1;
	int direc;
	int l;
};

class Pole {
protected:
	void setCursorPosition(int x, int y);
public:
	void vivod(string pole[11][11]);
	void clear(int(&pole)[10][10]);
	void zap(int(&pole)[10][10]);
	void zapoln(string(&pole)[11][11]);
	void menu();
};

class Play :public Pole{
private:
	Ships ships[10];
	int k = 1;
	int a = 0;
public:
	void Sozd(int(&pole)[10][10], int z, int x, int y, int s, Ships *ships);
	void Chetire(int(&pole)[10][10]);
	void Tri(int(&pole)[10][10]);
	void Dva(int(&pole)[10][10]);
	void Odin(int(&pole)[10][10]);
	void death(int i);
	void check(int(&pole)[10][10]);
	void Xod(int(&pole)[10][10]);
};
#endif	