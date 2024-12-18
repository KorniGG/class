#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Money
{
	long rubles;
	int kop;

public:

	Money();
	Money(long, int);
	Money(const Money&);
	Money operator =(const Money&);
	friend ostream& operator <<(ostream& out, const Money& m);
	friend istream& operator>>(istream& in, Money& m);
	bool operator==(const Money&); 
	bool operator!=(const Money&);
	Money& operator+(const Money&); 
	Money& operator--(); // Префиксный декремент
	Money operator--(int); // Постфиксный декремент
	Money& operator+(); 
	bool operator<(const Money& m);
	bool operator>(const Money& m);
	~Money();
	long get_rubles();
	int get_kop();


	friend fstream& operator>>(fstream& fin, Money& m);
	friend fstream& operator<<(fstream& fout, const Money& m);
};
