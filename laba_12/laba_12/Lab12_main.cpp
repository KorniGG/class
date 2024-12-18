#include <iostream>
#include <map>
using namespace std;

typedef multimap<int, float> TMap; // ���������� ��� ��� ������ � multimap
typedef TMap::iterator it;        // ��������

// ������� ��� ������������ multimap
TMap make_map(int n)
{
    TMap m; // ������ ���������
    float a;
    for (int i = 0; i < n; i++)
    {
        cout << "?";
        cin >> a;
        // ������� ���� � ��������� �� � multimap
        m.insert(make_pair(i, a));
    }
    return m; // ���������� ���������
}

// ������� ��� ������ multimap
void print_map(TMap m)
{
    for (auto& p : m)
        cout << p.first << " : " << p.second << endl;
}

// ���������� �������� ���������������
float srednee(TMap v)
{
    float s = 0;
    int n = 0; // ������� ���������
    for (auto& p : v)
    {
        s += p.second;
        n++;
    }
    return n > 0 ? s / n : 0;
}

// ����� ����� ������������� ��������
int Max(TMap v)
{
    it i = v.begin();
    int nom = i->first;
    float m = i->second; // �������� ������� ��������

    for (auto& p : v)
    {
        if (p.second > m)
        {
            m = p.second;
            nom = p.first;
        }
    }
    return nom; // ���������� ���� max
}

// ����� ������������ ��������
float Min(TMap v)
{
    if (v.empty())
    {
        throw runtime_error("��������� ����. ���������� ����� ����������� �������.");
    }

    it i = v.begin();
    float m = i->second; // �������� ������� ��������

    for (auto& p : v)
    {
        if (p.second < m)
        {
            m = p.second;
        }
    }
    return m; // ���������� ����������� ��������
}

// ���������� ������������ �������� �� �������� �������
void addMinElement(TMap& m, int pos, float minValue) {
    TMap newMap;
    int currentIndex = 0;

    for (auto it = m.begin(); it != m.end(); ++it) {
        if (currentIndex == pos) {
            newMap.insert(make_pair(pos, minValue)); // ��������� ����������� ������� �� ��������� �������
        }
        newMap.insert(make_pair(currentIndex, it->second)); // ��������� ������� �������
        currentIndex++;
    }

    if (pos >= currentIndex) {
        newMap.insert(make_pair(pos, minValue)); // ��������� � �����, ���� ������� �� ��������� �������� �������
    }

    m = newMap; // �������� ������������ ���������
}


// �������� ���������, �������� ������� ������ ��������
void removeAboveAverage(TMap& v)
{
    float average = srednee(v);

    for (auto it = v.begin(); it != v.end();)
    {
        if (it->second > average)
        {
            it = v.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

// ��������� ������� �������� �� ������������
void multiplyByMax(TMap& v)
{
    int maxIndex = Max(v);
    float maxValue = v.find(maxIndex)->second;

    for (auto& item : v)
    {
        item.second *= maxValue;
    }
}

// �������� �������
int main()
{
    setlocale(0, "Rus");
    int n;
    cout << "N?";
    cin >> n; // ���������� ���������
    TMap m = make_map(n); // ������� ���������
    print_map(m);         // ���������� ���������

    float min = Min(m);
    cout << "\n����������� ��������: " << min << "\n";

    cout << "pos?";
    int pos;
    cin >> pos;
    addMinElement(m, pos, min);
    cout << "����� ���������� ������������ �������� �� ������� " << pos << ":\n";
    print_map(m);

    removeAboveAverage(m);
    cout << "\n����� �������� ��������� ������ �������� ���������������:\n";
    print_map(m);

    multiplyByMax(m);
    cout << "\n����� ��������� ������� �������� �� ������������:\n";
    print_map(m);

    return 0;
}
