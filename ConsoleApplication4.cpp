// Create by John_29


#include <iostream>
using namespace std;
const int z = 10;
const int y = 10;
int main()
{
    setlocale(LC_ALL, "Russian");
    
    
   
    int a, b;   //task_1
    cout << "Введите первое число:";
    cin >> a  ;
    cout << "Введите второе число:";
    cin >> b;
    if ((a+b) >= 10 && (a+b) <=20)
        {
            cout << "true"<<endl;
        }
    else
        {
            cout << "false"<<endl;
        }
    cout << "-------------------------" << endl;

    //task_2
    if ( (z==10 && y==10) || (z + y == 10) ) 
    {
        cout << "true"<<endl;
    }
    
    /*if (z + y == 10)
    {
        cout << "true" << endl;
    }*/
    else
    {
        cout << "false" << endl;
    }
    cout << "-------------------------" << endl;
    
    //task_3
    for (int i = 1; i <= 50; i = i + 2) 
    {
        cout << i << " ";

    }
    cout << endl;
    cout << "-------------------------" << endl;

    //task_4
    int chislo;
    bool prostoe = true;
    cout << "Введите число:" << endl;
    cin >> chislo;
    
    for (int i = 2; i < chislo; i++)
        {
        
        if (chislo % i == 0)
            {
                prostoe = false;
            
                break;
            }
        
        }
    if (prostoe)
        {
            cout << "Простое"<<endl;
        }
    
    
    else
        {
            cout << "Не простое"<<endl;
        }
    // task_5
    int god;
    cout << "Введите год от 1 до 3000   :" << endl;
    cin >> god;
    if (((god % 4 == 0) && (god % 100 != 0)) || (god % 400 == 0))
        cout << "Високосный";
    else
        cout << "Не високосный";

    
}



