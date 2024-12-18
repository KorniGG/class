#include "fraction.h"
using namespace std;

// Реализация метода для инициализации полей структуры

void Fraction::Init(double F, double S) 
{
    first = F;
    second = S;
}


// Реализация метода для чтения значений полей структуры
void Fraction::Read()
{
    cout << "\nfirst?";
    cin >> first;
    cout << "\nsecond?";
    cin >> second;
}

// Реализация метода для вывода значений полей структуры
void Fraction::Show() const 
{
    cout << "\nfirst=" << first;
    cout << "\nsecond=" << second; 
    cout << "\n";
}


double Fraction::Hipotenuza()
{
    return sqrt(pow(first, 2) + pow(second, 2));

}
