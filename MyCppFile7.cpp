#include <iostream>

namespace MyLib
{
void printArray(const float array[], int size) 
	{
		for (int i = 0; i < size; i++)
			std::cout << array[i] << " ";
	}
	void podschet(const float array[], int size)
	{
		int plus = 0;
		int minus = 0;
		
		for (int i = 0; i < size; i++)
		{
			if (array[i] < 0)
				minus++;
			else if (array[i] > 0)
				plus++;
			
			else
			
				std::cout << " � ������� ���� ����"<<std::endl;
				
		}
		std::cout << "������������� " << plus << std::endl;
		std::cout << "������������� " << minus << std::endl;
	}
}