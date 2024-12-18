#include "DATE.h"

// Конструктор без параметров 
DATE::DATE(void) : TRIAD(1, 1, 1) {}

// Деструктор
DATE::~DATE(void) {}

// Конструктор с параметрами
DATE::DATE(int Y, int M, int D) : TRIAD(Y, M, D) {}

// Конструктор копирования
DATE::DATE(const DATE& D) : TRIAD(D.first, D.second, D.third) {}

// Модификаторы
void DATE::Set_year(int y) {
    first = y;
}

void DATE::Set_month(int m) {
    if (m >= 1 && m <= 12)
        second = m;
    else
        throw invalid_argument("Месяц должен быть в диапазоне от 1 до 12.");
}

void DATE::Set_day(int d) {
    if (d >= 1 && d <= 31)
        third = d;
    else
        throw invalid_argument("День должен быть в диапазоне от 1 до 31.");
}

// Увеличение года
void DATE::Increase_year() {
    Increase_first();
}

// Увеличение месяца
void DATE::Increase_month() {
    Increase_second();
    if (second > 12) {
        second = 1;
        Increase_year();
    }
}

// Переопределение метода увеличения дня
void DATE::Increase_day() {
    Increase_third();
    if (third > 31) {  // Условие для дней, без учета месяцев
        third = 1;
        Increase_month();
    }
}

// Метод добавления n дней
void DATE::Add_days(int n) {
    while (n > 0) {
        Increase_day();
        n--;
    }
}

// Операция присваивания
DATE& DATE::operator=(const DATE& d) {
    if (&d == this)
        return *this;
    TRIAD::operator=(d);
    return *this;
}

// Операция ввода
istream& operator>>(istream& in, DATE& d) {
    int y, m, d1;

    cout << "\nВведите год: ";
    while (!(in >> y)) {  // Если ввод не удалось
        in.clear();  // Очистить флаг ошибки
        in.ignore(numeric_limits<streamsize>::max(), '\n');  // Пропустить некорректный ввод
        cout << "Неверный ввод. Введите год: ";
    }

    cout << "Введите месяц: ";
    while (!(in >> m) || m < 1 || m > 12) {  // Проверка месяца
        in.clear();
        in.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Неверный месяц. Введите месяц (1-12): ";
    }

    cout << "Введите день: ";
    while (!(in >> d1) || d1 < 1 || d1 > 31) {  // Проверка дня
        in.clear();
        in.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Неверный день. Введите день (1-31): ";
    }

    // Если все значения корректны, присваиваем их объекту
    d.first = y;
    d.second = m;
    d.third = d1;

    return in;
}
// Операция вывода
ostream& operator<<(ostream& out, const DATE& d) {
    out << "\nДата: " << d.third << "/" << d.second << "/" << d.first;
    return out;
}
