// Create by John_29
#include <iostream>
#include <fstream>
#include "MyHeader7.h"
using namespace std;
#define QQQ(x,n) if (((x)>=0)&&((x)<(n))) std::cout<< "true"<<std::endl; else std::cout<< "false"<<std::endl;
#define ARR_SIZE 8
#define SWAPINT(t,a,b)   ( (t) = (a), (a) = (b), (b) = (t) )


#pragma pack(push, 1)
struct Sotrudnik
{
	string Name;			
	long Id;
	char Category;
	int Money_money;
};
#pragma pack(pop)


int main()
{
	int x;
	int n;
	
	int ar [ARR_SIZE];
	
	setlocale(LC_ALL, "Russian");
	cout << "Вывод массива на экран: " << std::endl;
	const int size = 5;
	float arr[size] = { 1.1, -2.2, 3.3, -4.4, 0 };
	MyLib::printArray(arr, size); 
	MyLib::podschet(arr,size);
	cout << "----------------------------task_1_5 " << std::endl;
	//task_2
	cout << "Введите число ";
	cin >> x;
	cout << "Введите число конечного диапозона " << endl;
	cin >> n;
	QQQ(x,n);
	cout << "----------------------------task_2 " << std::endl;
	//task_3
	cout << "Введите элементы массива для сортировки : "<<endl;
	for (int i = 0; i < ARR_SIZE; i++)
	{
		cin >> ar[i] ;
		
	}
	
	
	for (int i = 0; i < ARR_SIZE - 1; i++) {
		for (int j = 0; j < ARR_SIZE - i - 1; j++) {
			if (ar[j] > ar[j + 1])
			{
				 
				 int t;
				SWAPINT(t, ar[j], ar[j+1]);
			}
		}
	}
	cout << "Сортировка Пузырьком" << endl;
	for (int i = 0; i < ARR_SIZE; i++) {
		
		cout << ar[i] << " ";
	}
	cout <<endl;
	cout << "----------------------------task_3 " << std::endl;
	// Task_4
	Sotrudnik * pSotrudnik = new Sotrudnik;
	pSotrudnik->Id = 1;
	pSotrudnik->Name = "John";
	pSotrudnik->Category = 'A';
	pSotrudnik->Money_money = 100;

	cout << "Предаем данные структуры Сотрудник: " << endl;
	cout << pSotrudnik->Id << endl;
	cout << pSotrudnik->Name << endl;
	cout << pSotrudnik->Category << endl;
	cout << pSotrudnik->Money_money << endl;
	cout << sizeof(Sotrudnik) << " байт" << endl;		//с pragma-ой 37,а без 40 
	ofstream fout("Структура сотрудник.txt");
	fout << "Предаем данные структуры Сотрудник в файл : " << endl;
	fout << pSotrudnik->Id << endl;
	fout << pSotrudnik->Name << endl;
	fout << pSotrudnik->Category << endl;
	fout << pSotrudnik->Money_money << endl;
	delete pSotrudnik;
	fout.close();
	cout << "----------------------------task_4 " << std::endl;
	return 0;
}