#include <iostream>
#include < stdlib.h >
#include "fraction.h" // Подключаем заголовочный файл
using namespace std;

Fraction make_fraction(double F, int S)
{
    Fraction t; // Создали временную переменную
    t.Init(F, S); // Инициализировали поля переменной t с помощью параметров функции
    return t; // Вернули значение переменной t
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    // Объявление переменных A и B
    cout << "  \nсоздание экземпляра вручную:";
    Fraction A;
    Fraction B;

    A.Init(3.0, 4.0); // Инициализация переменной A
    B.Read(); // Чтение значений для переменной B
    cout << "\nавтоматически созданный экземпляр:";
    A.Show(); // Вывод значений переменной A
    cout << "\nэкземпляр, созданный вручную:";
    B.Show(); // Вывод значений переменной B

    //вычисление гипотенузы
    cout << " \nHipotenuza pri katetah: " << A.first << "," << A.second << "=" << A.Hipotenuza() << endl;
    cout << "Hipotenuza pri katetah: " << B.first << "," << B.second << "=" << B.Hipotenuza() << endl;

    cout << "  \n Динамическое выделение памяти для экземпляра: \n";
    // Динамическое выделение памяти для X
    Fraction* X = new Fraction;
    X->Init(9.0, 12.0); // Инициализация
    X->Show(); // Вывод значений
    cout << "Hipotenuza pri katetah: " << X->first << "," << X->second << "=" << X->Hipotenuza() << endl;

    cout << "  \n Создание массива экземпляров размерностью 3: \n";
    // Массивы
    Fraction mas[3]; // Определение массива
    for (int i = 0; i < 3; i++)
        mas[i].Read(); // Чтение значений полей
    for (int i = 0; i < 3; i++)
        mas[i].Show(); // Вывод значений полей
    for (int i = 0; i < 3; i++)
    {
        cout << "mas[" << i << "].Hipotenuza pri katetah: " << mas[i].first << "," << mas[i].second << "=" << mas[i].Hipotenuza() << endl;
    }

    cout << "  \n Создание динамического массива экземпляров размерностью 3: \n";
    // Динамические массивы
    Fraction* p_mas = new Fraction[3]; // Выделение памяти
    for (int i = 0; i < 3; i++)
        mas[i].Read(); // Чтение значений полей
    for (int i = 0; i < 3; i++)
        mas[i].Show(); // Вывод значений полей
    for (int i = 0; i < 3; i++)
    {
        cout << "mas[" << i << "].Hipotenuza pri katetah: " << mas[i].first << "," << mas[i].second << "=" << mas[i].Hipotenuza() << endl;
        
    }
    
    // Вызов функции make_fraction()
    cout << "  \n Создание экземпляра с помощью функции: \n";

    cout << "\n";
    double y;
    int z;
    cout << "first?";
    cin >> y;
    if (cin.fail()) {
        cout << "ERROR!!!! ";
        abort();
    }

    cout << "second?";
    cin >> z;
    if (cin.fail()) {
        cout << "ERROR!!!! ";
        abort();
    }

    
    // Переменная F формируется с помощью функции make_fraction()
    Fraction F = make_fraction(y, z);
    F.Show();
    cout << "Hipotenuza pri katetah: " << F.first << "," << F.second << "=" << F.Hipotenuza() << endl;

    // Освобождение динамической памяти
    delete X;
    delete[] p_mas;
    
    return 0;
}
