// ConsoleApp_Data_CSV.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include "Data_CSV.h"

int main()
{
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);

    setlocale(LC_ALL, "RUSSIAN");

    Data_CSV tab_1("data4.csv"); // Делаем запрос на внесение данных из файла "data.csv" в  таблицу tab_1;

     if (!tab_1.eof()) 
     {
         // Cоздаем dump.sql:

         tab_1.CREATE_DUMP_FILE("Dump3", "tab_5");  
         
     }
    else {
    
         std::cout << "Hello World!\n";
    
    }


     system("pause");
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
