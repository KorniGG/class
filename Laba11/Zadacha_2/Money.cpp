#include "Money.h"

// Конструктор по умолчанию
Money::Money(void)
{
    rubles = 0; // Инициализация рублей нулем
    kop = 0;    // Инициализация копеек нулем
}
Money::Money(float value)
{
    rubles = static_cast<long>(value);       // Целая часть — рубли
    kop = static_cast<int>((value - rubles) * 100); // Дробная часть — копейки
}

// Конструктор с параметрами
Money::Money(long r, int k)
{
    rubles = r; // Инициализация рублей заданным значением
    kop = k;    // Инициализация копеек заданным значением
}

// Конструктор копирования
Money::Money(const Money& t)
{
    rubles = t.rubles; // Копирование рублей из другого объекта
    kop = t.kop;       // Копирование копеек из другого объекта
}

// Перегрузка оператора присваивания
Money& Money::operator=(const Money& t)
{
    rubles = t.rubles; // Присваиваем рубли из другого объекта
    kop = t.kop;       // Присваиваем копейки из другого объекта
    return *this;      // Возвращаем ссылку на текущий объект
}

// Перегрузка оператора вывода (для вывода объекта в поток)
ostream& operator<<(ostream& out, const Money& t)
{
    out << t.rubles << "," << t.kop; // Вывод в формате "рубли,копейки"
    return out;                      // Возвращаем поток
}

// Перегрузка оператора ввода (для ввода объекта из потока)
istream& operator>>(istream& in, Money& t)
{
    cout << "Введите рубли: "; in >> t.rubles; // Ввод рублей
    cout << "Введите копейки: "; in >> t.kop; // Ввод копеек
    return in;                                // Возвращаем поток
}

// Перегрузка оператора != (неравенство)
bool Money::operator!=(const Money& t)
{
    // Возвращает true, если рубли или копейки отличаются
    return !(rubles == t.rubles && kop == t.kop);
}

// Перегрузка оператора == (равенство)
bool Money::operator==(const Money& t)
{
    // Возвращает true, если рубли и копейки равны
    return rubles == t.rubles && kop == t.kop;
}

// Перегрузка оператора < (меньше)
bool Money::operator<(const Money& t)
{
    if (rubles < t.rubles) return true;      // Сравнение рублей
    else if (rubles == t.rubles && kop < t.kop) return true; // Сравнение копеек
    return false; // Если ни одно из условий не выполнено
}

// Перегрузка оператора > (больше)
bool Money::operator>(const Money& t)
{
    if (rubles > t.rubles) return true;      // Сравнение рублей
    else if (rubles == t.rubles && kop > t.kop) return true; // Сравнение копеек
    return false; // Если ни одно из условий не выполнено
}

// Перегрузка оператора * (умножение)
Money Money::operator*(const Money& t)
{
    Money tmp;

    // Переводим оба объекта в копейки, но рассматриваем их как дробные числа
    float value1 = rubles + kop / 100.0f;  // Преобразуем первое значение в рубли как дробь
    float value2 = t.rubles + t.kop / 100.0f;  // Преобразуем второе значение в рубли как дробь

    // Перемножаем их как дробные числа
    float result_value = value1 * value2;

    // Преобразуем результат обратно в рубли и копейки
    tmp.rubles = static_cast<long>(result_value);  // Целая часть - рубли
    tmp.kop = static_cast<int>((result_value - tmp.rubles) * 100);  // Остаток - копейки

    return tmp;  // Возвращаем результат
}

Money Money::operator+(const Money& t)
{
    long total_kop = rubles * 100 + kop + t.rubles * 100 + t.kop;
    Money tmp;
    tmp.rubles = total_kop / 100;         // Преобразуем обратно в рубли
    tmp.kop = total_kop % 100;            // Оставшиеся копейки
    return tmp;
}




Money Money::operator/(int val)
{
    Money tmp; // Временный объект для результата
    long total_kop = rubles * 100 + kop; // Преобразуем сумму в копейки
    total_kop /= val;                    // Делим на переданное число

    tmp.rubles = total_kop / 100;        // Конвертируем обратно в рубли
    tmp.kop = total_kop % 100;           // Конвертируем обратно в копейки

    return tmp; // Возвращаем результат по значению
}
Money Money::operator/(float val) {
    if (val == 0.0f) {
        throw runtime_error("Деление на ноль!");
    }

    Money tmp;
    long total_kop = rubles * 100 + kop; // Преобразуем сумму в копейки
    float result = total_kop / val;     // Делим на float

    tmp.rubles = static_cast<long>(result) / 100; // Преобразуем обратно в рубли
    tmp.kop = static_cast<int>(result) % 100;    // Оставшиеся копейки
    return tmp;
}


Money::operator float() const
{
    return rubles + kop / 100.0f;
}