#include "Money.h"
#include <iostream>
using namespace std;

Money& Money::operator=(const Money& m) 
{
    if (this != &m) {
        rubles = m.rubles;
        kopecks = m.kopecks;
    }
    return *this;
}

Money& Money::operator--() // префиксная форма
{ 
    if (kopecks == 0) {
        rubles--;
        kopecks = 99;
    }
    else {
        kopecks--;
    }
    return *this;
}

Money Money::operator--(int) // постфиксная форма
{ 
    Money temp(*this);
    --(*this);
    return temp;
}

bool Money::operator==(const Money& m) const 
{
    return rubles == m.rubles && kopecks == m.kopecks;
}

bool Money::operator!=(const Money& m) const 
{
    return !(*this == m);
}

istream& operator>>(istream& in, Money& m) 
{
    cout << "Введите рубли: ";
    in >> m.rubles;
    cout << "Введите копейки: ";
    in >> m.kopecks;
    if (m.kopecks >= 100) {
        m.rubles += m.kopecks / 100;
        m.kopecks %= 100;
    }
    return in;
}

ostream& operator<<(ostream& out, const Money& m) 
{
    out << m.rubles << ',' << (m.kopecks < 10 ? "0" : "") << m.kopecks;
    return out;
}
