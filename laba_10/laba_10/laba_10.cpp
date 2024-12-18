#include <iostream>
#include <fstream>
#include <string>
#include "Money.h"
#include "file_work.h"
using namespace std;

void main()
{
	setlocale(0, "Rus");
	Money m, temp;
	int k, c, num, cnt;
	char file_name[30];
	do
	{					// меню
		cout << "\n0. Выход";
		cout << "\n1. Создать файл"; // создание файла
		cout << "\n2. Вывести файл"; // печать файла
		cout << "\n3. Удалить все записи большие заданного значения";
		cout << "\n4. Увеличить все записи с заданным значением на 1 руб 50 коп";
		cout << "\n5. Добавить K записей после записи с номером N\n";
		cin >> c;
        switch (c)
        {
        case 1:
            cout << "Название файла? ";
            cin >> file_name; // задаем имя файла
            k = make_file(file_name); // вызов функции для записи в файл
            if (k < 0) cout << "Не удается создать файл\n"; // вывод сообщения об ошибке
            break;
        case 2:
            cout << "Название файла? ";
            cin >> file_name;
            k = print_file(file_name);
            if (k == 0) cout << "Пустой файл\n";
            if (k < 0) cout << "Не удается прочитать файл\n";
            break;
        case 3:
            cout << "Название файла? ";
            cin >> file_name;
            cout << "Введите сумму: ";
            cin >> temp;
            k = del_file(file_name, temp);
            if (k < 0) cout << "Не удается прочитать файл\n";
            break;
        case 4:
            cout << "Название файла? ";
            cin >> file_name;
            cout << "Введите сумму: ";
            cin >> temp;
            k = change_file(file_name, temp);
            if (k < 0) cout << "Не удается прочитать файл";
            break;
        case 5:
            cout << "Название файла? ";
            cin >> file_name;
            cout << "Введите k: ";
            cin >> k;
            int a = add_file(file_name, k);
            if (a < 0) cout << "Не удается прочитать файл";
        }


	} while (c != 0);
}