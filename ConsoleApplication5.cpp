//Create by John_29

#include <iostream>

void arr(double a[], double n)  //task_1
{
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] <<" ";
    }
    std::cout << std::endl;
    std::cout <<"----------------------task_1"<< std::endl;
   
}

void arr2(int ar[], int n)          //task_2
{
    for (int i = 0; i < n; i++)
    {
        std::cout << ar[i]<<"";
    }
    std::cout << std::endl;
}

void arr0_1(int ar[], int n)
{
   
        for (int i = 0; i < n; i++)
            {
             ar[i] =(ar[i] > 0) ? 0 : 1;
               
            std::cout << ar[i];
            }
        std::cout << std::endl;
        std::cout << "----------------------task_2" << std::endl;
}

void arr_3(int ar[], int n)     //task_3
{
    for (int i = 0; i < n; i++)
    {
        ar[i] = i * 3;
        std::cout << ar[i]+1 << " ";
    }
    std::cout << std::endl;
    std::cout << "----------------------task_3" << std::endl;
}

void arr_sdvig(int ar[], int  n,int sdvig)       //task_4
{     

        for (int i = 0; i < n; i++)
        
            std::cout << ar[i]<<" ";
        std::cout << std::endl;
        int t = ar[0];
            for (int j = 0; j < n ; j++)
            {
                if (j == n - sdvig)
                {
                    ar[j] = t;
                    break;
                }
                ar[j] = ar[j + sdvig];
                
            }
            for (int j = 0; j < n; j++)
            {
                std::cout << ar[j] << " ";
            }
        
       
}
int main()
{
    int s = 1;
    int y = 8;
    int myarr3[8];
    int z = 5;
    double myarr[] = { 1.1,2.2,3.3,4.4,5.5 };
    int myarr4[5] = { 1,2,3,4,5 };
     arr(myarr,z);

     int myarr2[] = { 0,1,0,1,0 };
     arr2(myarr2, z);
     arr0_1(myarr2,z);
     arr_3(myarr3, y);
     arr_sdvig(myarr4, z,s);
}

