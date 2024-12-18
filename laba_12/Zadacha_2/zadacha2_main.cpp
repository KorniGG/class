#include <iostream>
#include <C:\Users\aisha\OneDrive\������� ����\����������� ��������\laba_11\Zadacha_2\Money.h>
#include <cstdlib>
#include <map>
using namespace std;

typedef multimap<int, Money> TMap; // ���������� multimap ������ map
typedef TMap::iterator it;

// ������� ��� ������������ �������
TMap make_map(int n) {
    TMap m; // ������ �������
    Money a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        // ������ ���� � ��������� � � �������
        m.insert(make_pair(i, a));
    }
    return m; // ���������� ������� ��� ��������� ������ �������
}

// ������� ��� ������ �������
void print_map(TMap m) {
    for (it i = m.begin(); i != m.end(); i++) {
        cout << i->first << " - " << i->second << " " << endl;
    }
}

// ���������� �������� ���������������
Money srednee(TMap m) {
    Money s = m.begin()->second; // ������ ������� � ��������� �������� �����
    // ������� �������
    for (it i = next(m.begin()); i != m.end(); i++) {
        s = s + i->second;
    }
    int n = m.size(); // ���������� ��������� � �������
    return s / n;
}

// ����� ������������� ��������
int Max(TMap v) {
    it i = v.begin();
    int nom = 0, k = 0;
    Money m = i->second; // �������� ������� ��������
    while (i != v.end()) {
        if (m < i->second) {
            m = i->second;
            nom = k;
        }
        i++; // ��������
        k++; // ������� ���������
    }
    return nom; // ����� max
}

// ����� ������������ ��������
int Min(TMap v) {
    it i = v.begin();
    int nom = 0, k = 0;
    Money m = i->second; // �������� ������� ��������
    while (i != v.end()) {
        if (m > i->second) {
            m = i->second;
            nom = k;
        }
        i++; // ��������
        k++; // ������� ���������
    }
    return nom; // ����� min
}

//����� ����������� ������� � �������� ��� �� �������� ������� ����������
void add_min_to_position(TMap& v, int pos) {
    // ��������� ������������ �������
    if (pos < 0 || pos > v.size()) {
        cout << "������: ������������ �������." << endl;
        return;
    }

    // ������� ����������� ��������
    it min_it = v.begin();
    for (it i = v.begin(); i != v.end(); ++i) {
        if (i->second < min_it->second) {
            min_it = i;
        }
    }
    Money min_value = min_it->second;

    // ��������� ����������� �������� � �������� ������ (���������� �������)
    v.insert(make_pair(pos, min_value));
}

//����� �������� ������� �������� ��������������� � ������� �� �� ����������
void removeGreaterThanAverage(TMap& m) {
    // ��������� ������� ��������������
    Money average = srednee(m);

    // �������� �� ���������� � ������� ��������, ������� ������ ��������
    for (auto it = m.begin(); it != m.end(); ) {
        if (it->second > average) {
            it = m.erase(it); // ������� ������� ������� � ��������� ��������
        }
        else {
            ++it; // ��������� � ���������� ��������
        }
    }
}

void multiplyByMax(TMap& m) {
    // ����� ������������� ��������
    Money maxValue = m.begin()->second; // �������� � ������� ��������
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (it->second > maxValue) {
            maxValue = it->second;
        }
    }

    // �������� ������ ������� �� ������������ ��������
    for (auto it = m.begin(); it != m.end(); ++it) {
        it->second = it->second * maxValue;
    }
}



// �������� �������
int main() {

    setlocale(0, "Rus");
    int n;
    cout << "N? ";
    cin >> n;
    TMap m = make_map(n); // ������� �������
    print_map(m); // ���������� �������


    //������� ��� ������� 
    cout << "pos?";
    int pos;
    cin >> pos;
    add_min_to_position(m, pos);
    cout << "����� ���������� ������������ �������� �� ������� " << pos << ":\n";
    print_map(m);

    removeGreaterThanAverage(m);
    cout << "\n����� �������� ��������� ������ �������� ���������������:\n";
    print_map(m);

    multiplyByMax(m);
    cout << "\n����� ��������� ������� �������� �� ������������:\n";
    print_map(m);



}
