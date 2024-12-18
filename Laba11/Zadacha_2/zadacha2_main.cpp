#include <iostream> 
#include <vector> 
#include <cstdlib> 
#include "Money.h" 
using namespace std;

typedef vector<Money>Vec;//���������� ��� ��� ������ � ��������
//������� ��� ������������ ������� 
Vec make_vector(int n)
{
	Vec v;//������ ������ 
	for (int i = 0; i < n; i++)
	{
		long r = rand() % 10;
		int k = rand() % 100;
		Money a(r, k);
		v.push_back(a);
	}
	return v;//���������� ������ ��� �������� ������ �������
}

//������� ��� ������ ������� 
void print_vector(Vec v)
{
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl;
}

// ������� ��� ������ ������������ �������� � �������
float find_min(const Vec& v)
{
	if (v.empty()) throw "Vector is empty!"; // ���������� ��� ������� �������

	float min_value = static_cast<float>(v[0]); // ����������� Money � float
	for (size_t i = 1; i < v.size(); i++) {
		if (static_cast<float>(v[i]) < min_value) // ���������� ��� float
			min_value = static_cast<float>(v[i]); // ��������� ����������� ��������
	}
	return min_value;
}

void add_vector(Vec& v, float el, int pos)
{
	// ����������� float � Money
	long rubles = static_cast<long>(el);       // ����� ����� � �����
	int kop = static_cast<int>((el - rubles) * 100); // ������� ����� � �������
	Money new_money(rubles, kop);

	// ��������� Money � ������
	v.insert(v.begin() + pos, new_money);
}

Money srednee(Vec v)
{
	if (v.empty()) throw "Vector is empty!";

	long total_kop = 0; // ����� ���� �������� � ��������
	for (const auto& money : v) {
		total_kop += money.get_rub() * 100 + money.get_kop(); // ��������� � ������� � ���������
	}

	long avg_kop = total_kop / v.size(); // ������� �������� � ��������

	return Money(avg_kop / 100, avg_kop % 100); // ����������� ������� � ����� � �������
}



// ������� ��� �������� ��������� ������ �������� ���������������
void remove_greater_than_avg(Vec& v)
{
	Money avg = srednee(v); // ������� ������� ��������������

	for (auto it = v.begin(); it != v.end();)
	{
		if (*it > avg) // ���������� �������� � ������� �������������� ��������� `>`
			it = v.erase(it); // ������� �������, ���� �� ������ ��������
		else
			++it; // ��������� � ���������� ��������
	}
}

// ������� ��� ������ ������������� �������� � �������
Money find_max(const Vec& v)
{
	if (v.empty()) throw "Vector is empty!"; // ���������� ��� ������� �������
	Money max_value = v[0]; // ������������� ������������� �������� ������ ���������
	for (size_t i = 1; i < v.size(); i++)
	{
		if (v[i] > max_value)
			max_value = v[i]; // ���������� ������������� ��������
	}
	return max_value;
}

// ������� ��� ��������� ������� �������� �� ������������ ������� �������
void multiply_by_max(Vec& v)
{
	if (v.empty()) throw "Vector is empty!"; // ���������� ��� ������� �������
	Money max_val = find_max(v); // ������� ������������ �������
	for (size_t i = 0; i < v.size(); i++)
	{
		v[i] = v[i] * max_val; // �������� ������ ������� �� ������������
	}
}


//�������� �������

void main()
{
	try
	{
		setlocale(0, "Rus");
		srand(static_cast<unsigned>(time(0)));
		vector<Money> v;  // ������ �������� ���� Money
		vector<Money>::iterator vi = v.begin();
		int n;
		cout << "N?";
		cin >> n;  // ������ ���������� ��������� � �������

		// ��������� ������
		v = make_vector(n);

		// �������� ������
		print_vector(v);
		float el = find_min(v);
		//������� ��� ������� 
		cout << "pos?";
		int pos;
		cin >> pos;
		//���������� ������, ���� ������� ��� ������� ������ ������� ������� 
		if (pos > v.size())throw 1;
		//����� ������� ��� ���������� 
		add_vector(v, el, pos);
		//������ �������
		cout << "������ ����� ���������� ������������ �������� �� ������� " << pos << ":\n";
		print_vector(v);
		remove_greater_than_avg(v);
		cout << "������ ����� �������� ��������� ������ �������� ���������������:\n ";
		print_vector(v); // ������ ������� ����� �������� ���������
		multiply_by_max(v);
		cout << "������ ����� ��������� ������� �������� �� ������������:\n";
		print_vector(v);
	}
	catch (int)  // ��������� ������
	{
		cout << "error!";
	}

}
