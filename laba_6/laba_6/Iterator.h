#pragma once
class Iterator
{
private:
	friend class Set;
	int* elem;
public:

	Iterator();

	void operator+(int n);

	void operator--();
	int& operator *() const;
};

