#pragma once

#include <iostream>
using namespace std;

class Money
{
public:
	Money(void);
	Money(long, int);
	Money(const Money&);
	Money& operator=(const Money&);

	friend ostream& operator<<(ostream& out, const Money&);
	friend istream& operator>>(istream& in, Money&);
	virtual ~Money(void) { rubles = 0; kop = 0; };

	Money operator-(const Money& other) const;
private:
	long rubles;
	int kop;
};
