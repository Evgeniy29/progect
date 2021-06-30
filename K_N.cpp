// Create by John_29

#include <iostream>

/*enum simvols_game { X, O, _ }; // Объявление перечисления символов
struct Game { char player_1, player_2;  bool sovershenie_hoda; short number_hod; };
union ifc 
{ 
   unsigned int isint : 29;
   bool isfloat : true;
   char ischar ;
};



int main()
{
    setlocale(LC_ALL, "Russian");
    // создание и инициализация переменных ДЗ_1
    int perem_int = 100;
    short int perem_short_int = 10;
    char perem_char = 'Z';
    bool perem_bool_1 = true;
    bool perem_bool_0 = false;
    float perem_float = 123.45;
    double perem_double = 123456789;
    long long perem_longlong = 987654321;
    std::cout << perem_int << std::endl;
    std::cout << perem_short_int << std::endl;
    std::cout << perem_char << std::endl;
    std::cout << perem_bool_1 << std::endl;
    std::cout << perem_bool_0 << std::endl;
    std::cout << perem_float << std::endl;
    std::cout << perem_double << std::endl;
    std::cout << perem_longlong << std::endl;
    std::cout << "------------------------" << std::endl;
    //-----------------------------------------
    //создание и инициализация массива способного содержать значения перечисления
    simvols_game simvol[3][3] = { {X,O,_},{O,X,_},{_,O,X} };

    std::cout << simvol[0][0] << std::endl;
    std::cout << simvol[1][0] << std::endl;
    std::cout << simvol[2][0] << std::endl;
    std::cout << "------------------------" << std::endl;


    // Создание структуры данных
 //__________________________________________________________

    Game e1, e2;
    e1.player_1 = 'x';
    e1.player_2 = 'o';
    e1.number_hod = 1;
    std::cout << "Введите номер хода 1 или 2 "<< std::endl;
    std::cin >> e1.number_hod;
    if (e1.number_hod <= 1)

        std::cout << "hod igroka X" << std::endl;

    else
        std::cout << "hod igroka O" << std::endl;

    
    e1.sovershenie_hoda = true;
    std::cout <<"Игрок:" << e1.player_1 << std::endl;
    std::cout <<"Игрок:" << e1.player_2 << std::endl;
    std::cout << "------------------------" << std::endl;
    //--------------------------------

    ifc q;
    q.isint = 100;
    std::cout << q.isint << std::endl;
    std::cout << q.isfloat << std::endl;
    std::cout << q.ischar << std::endl;
    
    
   
    

    std::cout << "------------------------" << std::endl;   
    //---------------------------------------   

    char arr[3][3] = {{'X','O','_'},{'O','X','_'},{'_','O','X'}};
    int i, j;
    std::cout << "Матрица 3 на 3: "<< std::endl;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            std::cout << " " << arr[2][0] ;
            
        }
        
        std::cout << std::endl;
    }
    std::cout << "Введите х: ";
    std::cin >> arr[0][0];                  // дальше что-то с памятью происходит в правой части экраны при отладке  (хотел создать чтоб ввод х и о был с клавиатуры , но пошел видимо не в то русло нужна не большая подсказка. )
    std::cout <<"размер массива в байтах:" << sizeof(arr) << std::endl;
    std::cout << "------------------------" << std::endl;
    //-------------------------------------------------

    */
enum TicTacToeCell {
    TC_EMPTY = '_',
    TC_CROSS = 'X',
    TC_ZERO = '0'
}; // Поле может содержать крестик, нолик или быть пустым

TicTacToeCell array[3][3] = { {TC_EMPTY, TC_EMPTY, TC_EMPTY},
{TC_EMPTY, TC_EMPTY, TC_EMPTY},
{TC_EMPTY, TC_EMPTY, TC_EMPTY} }; // поле для игры в крестики нолики 3 х 3

struct TicTacToe
{
    TicTacToeCell array[3][3]; // Как минимум структура должна содержать массив клеток игры
    bool isGameFinished;
    bool isFirstPlayerWon;
    long long Player1ID, Player2ID;
    TicTacToeCell ePlayer1, ePlayer2; // Чем ходит первый и второй игрок
    const unsigned int nFieldSize = 3;
};

union MyVariantData
{
    int MyInt;
    float MyFloat;
    char MyChar;
};

struct MyVariant
{
    MyVariantData data;
    unsigned int isInt : 1;
    unsigned int isChar : 1;
    unsigned int isFloat : 1;
};

int main()
{
    MyVariant var;

    var.data.MyFloat = 77.7777;
    var.isChar = 0;
    var.isFloat = 1; // Мы храним float
    var.isInt = 0;
     return 0;
};
    

    
   


