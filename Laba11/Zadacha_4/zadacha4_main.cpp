#include <C:\Users\aisha\OneDrive\������� ����\����������� ��������\laba_11\Zadacha_2\Money.h>
#include <iostream>
#include <queue>  // ���������� ������� � ������������
#include <vector>
using namespace std;

typedef priority_queue<Money> PQ;  // ������� � ������������ ��� �������� Money
typedef vector<Money> Vec;  // ������ ��� �������� Money

// ������� ��� �������� ������� � ������������
PQ make_priority_queue(int n) {
    PQ pq;
    Money m;
    for (int i = 0; i < n; i++) {
        cin >> m;  // ���� ��������
        pq.push(m); // ���������� � ������� � ������������
    }
    return pq;
}

// ������� ��� ������ ������� � ������������
void print_priority_queue(PQ pq) {
    PQ temp = pq;
    while (!temp.empty()) {
        cout << temp.top() << " ";  // ����� ��������
        temp.pop();  // ������� ��� �� �������
    }
    cout << endl;
}

// �������� ������� � ������������ � ������
Vec copy_priority_queue_to_vector(PQ pq) {
    Vec v;
    while (!pq.empty()) {
        v.push_back(pq.top());  // �������� ������� � ��������� �����������
        pq.pop();
    }
    return v;
}

// �������� ������ � ������� � ������������
PQ copy_vector_to_priority_queue(Vec v) {
    PQ pq;
    for (int i = 0; i < v.size(); i++) {
        pq.push(v[i]);
    }
    return pq;
}

// ����� ������������ �������� � ������� � ������������
Money Min(PQ pq) {
    Money m = pq.top();  // �������������� ����������� ������� ������ ���������
    PQ temp = pq;  // ������� ����� �������
    while (!temp.empty()) {
        if (temp.top() < m) {
            m = temp.top();  // ��������� ����������� �������
        }
        temp.pop();
    }
    return m;
}

// ���������� �������� � ������� � ������������ �� ��������� �������
void Add_to_priority_queue(PQ& pq, Money el, int pos) {
    Vec v = copy_priority_queue_to_vector(pq);  // �������� ������� � ������
    if (pos < 1 || pos > v.size() + 1) {
        cout << "�������� �������!" << endl;
        return;
    }
    v.insert(v.begin() + pos - 1, el);  // ��������� ������� �� ������� (��������� � 1)
    pq = copy_vector_to_priority_queue(v);  // �������� ������ ������� � ������� � ������������
}

// ���������� �������� ��������
Money Srednee(PQ pq) {
    Vec v = copy_priority_queue_to_vector(pq);  // �������� ������� � ������
    int n = 1;
    Money sum = pq.top();  // ��������� �������� ��� �����
    pq.pop();  // ������� ������ �������
    while (!pq.empty()) {  // ���� ������� �� �����
        sum = sum + pq.top();  // �������� � ����� �������
        pq.pop();  // ������� �������
        n++;
    }
    pq = copy_vector_to_priority_queue(v);  // ��������������� �������
    return sum / n;  // ���������� ������� ��������������
}

// �������� ��������� ������ �������� ���������������
void RemoveGreaterThanAverage(PQ& pq) {
    Money average = Srednee(pq);  // �������� ������� ��������������
    Vec v = copy_priority_queue_to_vector(pq);  // �������� ������� � ������
    PQ new_pq;  // ����� ������� ��� ���������, �� ����������� �������

    // �������� �� ���� ��������� ������� � ��������� � ����� ������� ������ ��, ������� ������ ��� ����� ��������
    for (int i = 0; i < v.size(); i++) {
        if (v[i] <= average) {
            new_pq.push(v[i]);
        }
    }

    // �������������� ������� �����
    pq = new_pq;
}

// ����� ������������� �������� � ������� � ������������
Money Max(PQ pq) {
    Money m = pq.top();  // ���������� m ����������� �������� �� �������
    PQ temp = pq;  // ������� ����� �������
    while (!temp.empty()) {  // ���� ������� �� �����
        if (temp.top() > m) m = temp.top();  // ���������� m � �������
        temp.pop();  // ������� ������� �� �������
    }
    return m;  // ���������� m
}

// ��������� ������� �������� �� ������������ �������
void MultiplyByMax(PQ& pq) {
    Money max_elem = Max(pq);  // ������� ������������ �������
    Vec v = copy_priority_queue_to_vector(pq);  // �������� ������� � ������
    PQ new_pq;  // ����� ������� ��� �������� �����������

    // �������� �� ���� ��������� ������� � �������� �� �� ������������ �������
    for (int i = 0; i < v.size(); i++) {
        Money result = v[i] * max_elem;  // �������� ������� �� ������������
        new_pq.push(result);  // ��������� ��������� � ����� �������
    }

    // �������������� ������� ������ ����������
    pq = new_pq;
}

int main() {
    setlocale(0, "Rus");

    Money m;
    PQ pq;
    int n;
    cout << "������� ���������� ��������� � ������� � ������������: ";
    cin >> n;

    pq = make_priority_queue(n);  // ������� ������� � ������������
    cout << "�������� ������� � ������������:\n";
    print_priority_queue(pq);  // ������ ������� � ������������

    m = Min(pq);  // ������� ����������� �������
    cout << "����������� �������: " << m << endl;

    cout << "������� ������� ��� ������� ������������ ��������: ";
    int pos;
    cin >> pos;

    // ���������� ������������ �������� � �������
    Add_to_priority_queue(pq, m, pos);

    cout << "������� ����� ���������� ������������ �������� �� ������� " << pos << ":\n";
    print_priority_queue(pq);  // ������ ������� ����� ���������

    RemoveGreaterThanAverage(pq);
    cout << "������� ����� �������� ��������� ������ �������� ���������������:\n";
    print_priority_queue(pq);  // ������ ������� ����� ��������

    MultiplyByMax(pq);
    cout << "������� ����� ��������� ������� �������� �� ������������:\n";
    print_priority_queue(pq);  // ������ ������� ����� ���������

    return 0;
}
