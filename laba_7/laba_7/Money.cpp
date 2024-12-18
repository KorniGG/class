#include "Money.h"

// Конструктор по умолчанию
Money::Money(void)
{
    rubles = 0; // Инициализация рублей
    kop = 0;    // Инициализация копеек
}

// Конструктор с параметрами
Money::Money(long r, int k)
{
    rubles = r; // Инициализация рублей
    kop = k;    // Инициализация копеек
}

// Конструктор копирования
Money::Money(const Money& t)
{
    rubles = t.rubles; // Копируем рубли
    kop = t.kop;       // Копируем копейки
}

// Перегрузка оператора присваивания
Money& Money::operator=(const Money& t)
{
    rubles = t.rubles; // Присваиваем рубли
    kop = t.kop;       // Присваиваем копейки
    return *this;      // Возвращаем текущий объект
}

// Перегрузка оператора вывода
ostream& operator<<(ostream& out, const Money& t)
{
    out << t.rubles << " рублей, " << t.kop << " копеек"; // Вывод рублей и копеек
    return out;
}

// Перегрузка оператора ввода
istream& operator>>(istream& in, Money& t)
{
    cout << "Введите рубли: ";
    in >> t.rubles; // Ввод рублей
    cout << "Введите копейки: ";
    in >> t.kop;    // Ввод копеек
    return in;
}

// Перегрузка оператора "-" для вычисления разности
Money Money::operator-(const Money& other) const
{
    // Переводим рубли и копейки в общую сумму в копейках
    long totalKop1 = rubles * 100 + kop;         // Общая сумма текущего объекта
    long totalKop2 = other.rubles * 100 + other.kop; // Общая сумма вычитаемого объекта

    // Вычисляем разность в копейках
    long resultKop = totalKop1 - totalKop2;

    // Преобразуем обратно в рубли и копейки
    long resultRubles = resultKop / 100;          // Целая часть от деления
    int resultKopRemainder = resultKop % 100;     // Остаток от деления

    // Если остаток копеек отрицательный, корректируем результат
    if (resultKopRemainder < 0)
    {
        resultRubles -= 1;              // Уменьшаем рубли на 1
        resultKopRemainder += 100;      // Увеличиваем копейки на 100
    }

    // Возвращаем новый объект Money с результатом
    return Money(resultRubles, resultKopRemainder);
}
