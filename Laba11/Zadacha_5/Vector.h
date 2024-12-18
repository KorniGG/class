#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template<class T>
class Vector {
    priority_queue<T> s;  // ��������� (������� � �����������)
    int len;              // ������ ����������
public:
    Vector();                      // ����������� ��� ����������
    Vector(int n);                  // ����������� � ����������
    Vector(const Vector<T>& Vec);   // ����������� �����������
    void Print();                   // ������

    T Min();
    void Add(T el, int pos);
    T Srednee();
    void RemoveGreaterThanAverage();
    T Max();
    void MultiplyByMax();
};

// ����������� ������� � ����������� � ������
template <class T>
vector<T> copy_queue_to_vector(priority_queue<T> s) {
    vector<T> v;
    while (!s.empty()) {
        v.push_back(s.top());
        s.pop();
    }
    return v;
}

// ����������� ������� � ������� � �����������
template <class T>
priority_queue<T> copy_vector_to_queue(vector<T> v) {
    priority_queue<T> s;
    for (int i = 0; i < v.size(); i++) {
        s.push(v[i]);
    }
    return s;
}

// ����������� ��� ����������
template <class T>
Vector<T>::Vector() {
    len = 0;
}

// ����������� � ����������
template <class T>
Vector<T>::Vector(int n) {
    T a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        s.push(a);  // �������� � ������� � ����������� �������
    }
    len = s.size();
}

// ����������� �����������
template <class T>
Vector<T>::Vector(const Vector<T>& Vec) {
    len = Vec.len;
    // �������� �������� ������� � ����������� Vec.s � ������ v
    vector<T> v = copy_queue_to_vector(Vec.s);
    // �������� ������ v � ������� � ����������� s
    s = copy_vector_to_queue(v);
}

// ������
template <class T>
void Vector<T>::Print() {
    // ������� ��������� ����� ������� � ����������� ��� ������
    priority_queue<T> temp = s;
    while (!temp.empty()) {
        cout << temp.top() << " ";  // ������� ������� �� ������� �������
        temp.pop();  // ������� ������� �� ��������� �������
    }
}

// ����� ������������ ��������
template <class T>
T Vector<T>::Min() {
    T m = s.top();
    vector<T> v = copy_queue_to_vector(s);
    while (!s.empty()) {
        if (s.top() < m) m = s.top();
        s.pop();
    }
    s = copy_vector_to_queue(v);
    return m;
}

// ���������� �������� el � ������� �� ������� pos
template <class T>
void Vector<T>::Add(T el, int pos) {
    vector <T> v; // ��������������� ������
    int i = 1;
    vector<T> tmp = copy_queue_to_vector(s); // �������� ������� � ������
    while (!tmp.empty()) {
        if (i == pos) v.push_back(el);  // ���� ����� ������� ���������, ��������� ����� �������
        v.push_back(tmp.back());  // ��������� ������� � ������
        tmp.pop_back();  // ������� ������� �� �������
        i++;
    }
    s = copy_vector_to_queue(v);  // �������� ������ ������� � ������� � �����������
}

// ������� ��������������
template <class T>
T Vector<T>::Srednee() {
    vector<T> v = copy_queue_to_vector(s);
    int n = 1;  // ���������� ��������� � �������
    T sum = s.top();  // ��������� �������� ��� �����
    s.pop();  // ������� ������� �� ������� �������
    while (!s.empty()) {
        sum = sum + s.top();  // ��������� � ����� ������� �� ������� �������
        s.pop();  // ������� ������� �� ������� �������
        n++;  // ����������� ���������� ���������
    }
    s = copy_vector_to_queue(v);  // �������� ������ ������� � ������� � �����������
    return sum / n;
}

template <class T>
void Vector<T>::RemoveGreaterThanAverage() {
    // ������� ��������� ������� ��������������
    T average = Srednee();

    // �������� ������� � ������
    vector<T> v = copy_queue_to_vector(s);

    // ������� ����� ��������� ��� ���������� ���������, ������� ������ ��� ����� ��������
    priority_queue<T> new_queue;

    // �������� �� ���� ��������� �������
    for (int i = v.size() - 1; i >= 0; i--) {
        if (v[i] <= average) {
            new_queue.push(v[i]);  // ���� ������� ������ ��� ����� ��������, ��������� � ����� ���������
        }
    }

    // �������� �������� ������� � ������������ �������
    s = new_queue;
}

// ����� ������������� ��������
template <class T>
T Vector<T>::Max() {
    T m = s.top();  // m ��������� �������� �� ������� �������
    vector<T> v = copy_queue_to_vector(s);
    while (!s.empty()) {
        if (s.top() > m) m = s.top();
        s.pop();  // ������� ������� �� ������� �������
    }
    s = copy_vector_to_queue(v);  // �������� ������ ������� � ������� � �����������
    return m;
}

template <class T>
void Vector<T>::MultiplyByMax() {
    // ������� ������������ �������
    T max_val = Max();

    // �������� ������� � ������
    vector<T> v = copy_queue_to_vector(s);

    // ������� ����� ��������� ��� �������� ���������� ���������
    priority_queue<T> new_queue;

    // �������� �� ���� ��������� ������� � �������� �� �� ������������ �������
    for (int i = v.size() - 1; i >= 0; i--) {
        new_queue.push(v[i] * max_val);  // �������� ������� �� ������������
    }

    // �������� ����� ��������� ������� � ������������ �������
    s = new_queue;
}

