// Create by John_29
#include <iostream>
#include <random>
#include <stdlib.h>
#include <chrono>
#include <windows.h>
using namespace std;

enum Ycheyka
{
	Krestik = 'X',
	Nolik = 'O',
	Pustota = '_'
};

struct CoordField
{
	size_t y;
	size_t x;
};

enum GameProgress
{
	InProcesse,
	WinnerChelovek,
	WennerComp,
	DRAW

};
struct Field
{
	Ycheyka** ppField = nullptr; //Наше поле
	const size_t SIZE = 3;
	size_t xod = 0; // чей ход
	GameProgress process = InProcesse;
	Ycheyka Comp; // чем играет 
	Ycheyka Chelovek;//

};

GameProgress Winner(const Field& f);

void clearScr()
{
	system("cls");
}
int32_t getRandomNum(int32_t min, int32_t max)
{
	const static auto seed = chrono::system_clock::now().time_since_epoch().count();
	static mt19937_64 generator(seed);
	uniform_int_distribution<int32_t> dis(min, max);
	return dis(generator);
}
void initField(Field& f)
{//появляется поле для игры
	f.ppField = new (nothrow) Ycheyka * [f.SIZE];
	for (size_t i = 0; i < f.SIZE; i++)
	{
		f.ppField[i] = new(nothrow) Ycheyka[f.SIZE];
	}
	for (size_t y = 0; y < f.SIZE; y++)
	{
		for (size_t x = 0; x < f.SIZE; x++)
		{
			f.ppField[y][x] = Pustota;
		}
	}
	//кто чем играет
	if (getRandomNum(0, 1000) > 500)
	{
		f.Chelovek = Krestik;
		f.Comp = Nolik;
		f.xod = 0;
	}
	else
	{
		f.Chelovek = Nolik;
		f.Comp = Krestik;
		f.xod = 1;
	}
}
void deinitField(Field& f)
{
	for (size_t i = 0; i < f.SIZE; i++)
	{
		delete[] f.ppField[i];
	}
	delete[] f.ppField;
	f.ppField = nullptr;
}
void printField(const Field& f)
{//рисование поля
	cout << "Человек: " << (char)f.Chelovek << endl;
	cout << "Комп: " << (char)f.Comp << endl;
	cout << "     ";
	for (size_t x = 0; x < f.SIZE; x++)

		cout << x + 1 << "   ";
	cout << endl;

	for (size_t y = 0; y < f.SIZE; y++)
	{
		cout << " " << y + 1 << " | ";
		for (size_t x = 0; x < f.SIZE; x++)
		{
			cout << (char)f.ppField[y][x] << " | ";
		}
		cout << endl;
	}
	cout << endl;
}
CoordField CoordChelovek(const Field& f)	//ходит чел
{
	CoordField c_xy{ 0,0 };

	do
	{

		cout << "Введите координату Х: ";
		cin >> c_xy.x;
		cout << "Введите координату Y: ";
		cin >> c_xy.y;
		/*if (cin.fail())
		{
			cin.clear();
		}*/
	} while (c_xy.x == 0 || c_xy.y == 0 || c_xy.x > 3 || c_xy.y > 3 || f.ppField[c_xy.y - 1][c_xy.x - 1] != Pustota);
	c_xy.x--;
	c_xy.y--;
	return c_xy;
}
CoordField CoordComp(Field& f)	//ходит комп
{
	//предвыигрыш
	for (size_t x = 0; x < f.SIZE; x++)
	{
		for (size_t y = 0; y < f.SIZE; y++)
		{
			if (f.ppField[y][x] == Pustota)
			{
				f.ppField[y][x] = f.Comp;
				if (Winner(f) == WennerComp)
				{
					f.ppField[y][x] = Pustota;
					return { y,x };
				}
				f.ppField[y][x] = Pustota;
			}
		}
	}
	//-----предпроигрыш
	for (size_t x = 0; x < f.SIZE; x++)
	{
		for (size_t y = 0; y < f.SIZE; y++)
		{
			if (f.ppField[y][x] == Pustota)
			{
				f.ppField[y][x] = f.Chelovek;
				if (Winner(f) == WinnerChelovek)
				{
					f.ppField[y][x] = Pustota;
					return { y,x };
				}
				f.ppField[y][x] = Pustota;
			}
		}
	}
	CoordField c_xy;
	if (f.ppField[1][1] == Pustota)
	{
		return { 1,1 };	//центр
	}
	//----------------
	if (f.ppField[0][0] == Pustota)
	{
		return { 0,0 };
	}
	if (f.ppField[2][2] == Pustota)
	{
		return { 2,2 };					//углы
	}
	if (f.ppField[2][0] == Pustota)
	{
		return { 2,0 };
	}
	if (f.ppField[0][2] == Pustota)
	{
		return { 0,2 };
	}
	//---------------------------
	if (f.ppField[0][1] == Pustota)
	{
		return { 0,1 };
	}
	if (f.ppField[2][1] == Pustota)
	{
		return { 2,1 };					//крест +
	}
	if (f.ppField[1][0] == Pustota)
	{
		return { 1,0 };
	}
	if (f.ppField[1][2] == Pustota)
	{
		return { 1,2 };
	}
}
GameProgress Winner(const Field& f) // прорверка выигрыша //поробовать заменить на циклы
{
	for (size_t y = 0; y < f.SIZE; y++)
	{
		if (f.ppField[y][0] == f.ppField[y][1] && f.ppField[y][0] == f.ppField[y][2])
		{
			if (f.ppField[y][0] == f.Comp)
				return WennerComp;
			if (f.ppField[y][0] == f.Chelovek)
				return WinnerChelovek;
		}
	}
	for (size_t x = 0; x < f.SIZE; x++)
	{
		if (f.ppField[0][x] == f.ppField[1][x] && f.ppField[0][x] == f.ppField[2][x])
		{
			if (f.ppField[0][x] == f.Comp)
				return WennerComp;
			if (f.ppField[0][x] == f.Chelovek)
				return WinnerChelovek;
		}
	}
	if (f.ppField[0][0] == f.ppField[1][1] && f.ppField[0][0] == f.ppField[2][2])	//диаг
	{
		if (f.ppField[0][0] == f.Comp)
			return WennerComp;
		if (f.ppField[0][0] == f.Chelovek)
			return WinnerChelovek;
	}
	if (f.ppField[0][2] == f.ppField[1][1] && f.ppField[2][0] == f.ppField[1][1])//даиг
	{
		if (f.ppField[1][1] == f.Comp)
			return WennerComp;
		if (f.ppField[1][1] == f.Chelovek)
			return WinnerChelovek;
	}
	bool draw = true;	//наступила ли ничья
	for (size_t y = 0; y < f.SIZE; y++)
	{
		for (size_t x = 0; x < f.SIZE; x++)
		{
			if (f.ppField[y][x] == Pustota)
			{
				draw = false;
				break;
			}
		}
		if (!draw)
		{
			break;
		}
	}
	if (draw)
	{
		return DRAW;
	}

	return InProcesse;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	Field f;
	clearScr();
	initField(f);
	printField(f);
	do
	{
		if (f.xod % 2 == 0)
		{
			CoordField c_xy = CoordChelovek(f);//ход человека
			f.ppField[c_xy.y][c_xy.x] = f.Chelovek;
		}
		else
		{
			CoordField c_xy = CoordComp(f);
			f.ppField[c_xy.y][c_xy.x] = f.Comp;//ход комп
		}
		clearScr();
		printField(f);
		f.xod++;
		f.process = Winner(f);
	} while (f.process == InProcesse);
	if (f.process == WinnerChelovek)
	{
		cout << "Выиграл Человек" << endl;
	}
	else if (f.process == WennerComp)
	{
		HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "Выиграл Комп" << endl;
	}
	else if (f.process == DRAW)
	{
		HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hOUTPUT, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "Ничья" << endl;
	}
	deinitField(f);
	return 0;
}

