// Create by John_29
//

#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

void stepen_2(int *ar,int n)        //task_1
{
    std::cout << "Введите размер массива: ";
    std::cin >> n;
    ar = new int[n];
    int t = 1;
    std::cout << "Вывод массива: ";
    for (int i = 0; i < n; i++)
        {
            ar[i] = t;
            std::cout << ar[i] << " ";
            t *= 2;
        }
    std::cout << std::endl;
    delete[] ar;
}

void matrix_rand(int **ar,int n,int m)      //task_2
{
    
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            {
        
                 ar[i][j] = rand() % 100;
        
            }
    
            
    
}

void matrix_cout(int** ar, int n, int m)
{
    std::cout << "Вывод матрицы : " << std::endl;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                std::cout << ar[i] [j]<<" ";
                
            }
            std::cout << std::endl;
        }
        
}

void fail_1()       //task_3
{
    string textfail;
     string text1 = "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww";
    cout << "Введите название файла №1: ";
    cin >> textfail;
    textfail += ".txt";
    
    ofstream fout( textfail);
   

    fout << text1 << endl;

    fout.close();
}
void fail_2()
{
    string textfail;
    string text2 = "qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq";
    cout << "Введите название файла №2: ";
    cin >> textfail;
    textfail += ".txt";
    ofstream fout(textfail);

    fout << text2 << endl;

    fout.close();
}

void sliyanieFails()        //task_4
{
    string textfail1;
    string text1 = "* Написать функцию, «склеивающую» эти файлы в третий текстовый файл (имя файлов спросить у пользователя).";
    string textfail2;
    string text2 = "* Написать программу, которая проверяет присутствует ли указанное пользователем при запуске программы слово в указанном пользователем файле (для простоты работаем только с латиницей).";
    string textfail3;
    cout << "Введите название файла №1: ";
    cin >> textfail1;
    textfail1 += ".txt";
    ofstream fout1(textfail1);
    if (fout1.is_open())
    {
        fout1 << text1;
    }
    cout << "Введите название файла №2: ";
    cin >> textfail2;
    textfail2 += ".txt";
    ofstream fout2(textfail2);
    if (fout2.is_open())
    {
        fout2 << text2;
    }
    cout << "Введите название файла слияния №3: ";
    cin >> textfail3;
    textfail3 += ".txt";
    ofstream fout3(textfail3);
    fout3 << text1 << text2;
    fout1.close();
    fout2.close();
    fout3.close();
   
}

void poisk()        //task_5
{
    string str = "Урок 6. Управление памятью. Ссылки и указатели, именование, арифметика, функции обратного вызова";
    ofstream fout("textfail.txt");
    if (fout.is_open())
    {
        fout << str;
    }
    
    if (str.find("Ссылки") != string::npos)
    {
        cout << "Найдено";
    }
    else
    {
        cout << "Не найдено";
    }
    fout.close();
}

int main()
{
    setlocale(LC_ALL, "Russian");
    
    int z=4;
    int y=4;
    int s=5;
    int** a;
    a = new int* [z];
    for (int i=0; i < z; i++)
        a[i] = new int[y];
    stepen_2(&z,s);
    matrix_rand(a,z,y);
    matrix_cout(a,z,y);
    for (int i=0; i < z; i++)
        delete[] a[i];
    delete[] a;
    fail_1();
    fail_2();
    sliyanieFails();
    poisk();
    return 0;
}