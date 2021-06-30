// Create by John_29

#include <iostream>
using namespace std;
extern int a, b, c, d; //дз4
int main()
{
	setlocale(LC_ALL, "Russian");

	//int a = 2, b = 10, c = 29, d = 9;                     //дз1
	float cd = static_cast <float> (c) / d;
	//float cd = float (c) / d;
	std::cout << a * (b + cd)<<std::endl;
	//std::cout << a * (b + (float(c) / d));
	std::cout << "------------------------------ДЗ_1 и 4" << std::endl;

	int z = 20, y, q = 22, g;
	y = (z <= 21) ? z-21 : (z-21)*2; // если число <= 21
	std::cout << "Если данное число <= 21 " << std::endl;
	std::cout << y << std::endl;

	g = (q > 21) ? (q - 21) * 2 : q - 21; // если число > 21
	std::cout << "Если данное число > 21 " << std::endl;
	std::cout << g << std::endl;

	std::cout << "------------------------------ДЗ_2" << std::endl;


	int Array[3][3][3];
	int* ptrArray = & Array[1][1][1];
	*ptrArray = 111;
	cout << Array[1][1][1]<<endl;
	std::cout << "------------------------------ДЗ_3" << std::endl;
	return 0;
}

