#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

const int nm = 5;

vector<vector<int>> a;
int n;

// ������� ��� ����������� �������
void displayMatrix() {
    cout << "������� �������:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == -1)
                cout << " -1 ";
            else if (a[i][j] == -2)
                cout << " -2 ";
            else
                cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---------------------" << endl;
}

void makeBase(int ik, int jk) {
    for (int i = 0; i < n; i++)
        if (a[i][jk] >= 0)
            a[i][jk] = -1;

    for (int j = 0; j < n; j++)
        if (a[ik][j] >= 0)
            a[ik][j] = -1;

    a[ik][jk] = -2;

    if (a[jk][ik] >= 0)
        a[jk][ik] = -1;

    // ���������� ������� ����� ���������� makeBase
    cout << "����� ���������� makeBase(" << ik + 1 << ", " << jk + 1 << "):" << endl;
    displayMatrix();
}

int main() {
    setlocale(0, "Rus");

    ifstream f("mx.txt");
    if (!f) {
        cerr << "������: �� ������� ������� ���� mx.txt!" << endl;
        return 1;
    }

    f >> n;
    a.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            f >> a[i][j];

    f.close();

    // ������������� ������������ ���������
    for (int i = 0; i < n; i++)
        a[i][i] = -1;

    // ���������� ��������� �������
    cout << "��������� �������:" << endl;
    displayMatrix();

    for (int c = 0; c < n; c++) {
        // ���� �������, ������� ����������� ������ ���� ��� � ������ ��� �������
        int flag = 0, i2 = -1, j2 = -1;

        for (int i = 0; i < n && flag == 0; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (a[i][j] >= 0) {
                    i2 = i;
                    j2 = j;
                    cnt++;
                }
            }
            if (cnt == 1) flag = 1;
        }

        for (int j = 0; j < n && flag == 0; j++) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (a[i][j] >= 0) {
                    i2 = i;
                    j2 = j;
                    cnt++;
                }
            }
            if (cnt == 1) flag = 1;
        }

        if (flag == 1) {
            makeBase(i2, j2);
            continue;
        }

        // �������� ����������� �������� �� �����
        for (int i = 0; i < n; i++) {
            int minv = numeric_limits<int>::max();
            for (int j = 0; j < n; j++)
                if (a[i][j] >= 0 && a[i][j] < minv)
                    minv = a[i][j];

            for (int j = 0; j < n; j++)
                if (a[i][j] >= 0)
                    a[i][j] -= minv;
        }

        // ���������� ������� ����� ��������� �� �������
        cout << "����� ��������� ����������� ��������� �� �����:" << endl;
        displayMatrix();

        // �������� ����������� �������� �� ��������
        for (int j = 0; j < n; j++) {
            int minv = numeric_limits<int>::max();
            for (int i = 0; i < n; i++)
                if (a[i][j] >= 0 && a[i][j] < minv)
                    minv = a[i][j];

            for (int i = 0; i < n; i++)
                if (a[i][j] >= 0)
                    a[i][j] -= minv;
        }

        // ���������� ������� ����� ��������� �� ��������
        cout << "����� ��������� ����������� ��������� �� ��������:" << endl;
        displayMatrix();

        // ����� ������� ��������
        int maxv = -1, i3 = -1, j3 = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 0) {
                    int miniv = numeric_limits<int>::max();
                    int minjv = numeric_limits<int>::max();

                    for (int i2 = 0; i2 < n; i2++)
                        if (a[i2][j] >= 0 && i2 != i && a[i2][j] < miniv)
                            miniv = a[i2][j];

                    for (int j2 = 0; j2 < n; j2++)
                        if (a[i][j2] >= 0 && j2 != j && a[i][j2] < minjv)
                            minjv = a[i][j2];

                    if (miniv + minjv > maxv) {
                        maxv = miniv + minjv;
                        i3 = i;
                        j3 = j;
                    }
                }
            }
        }

        makeBase(i3, j3);
    }

    // ����� ��������
    int i2 = 0;
    cout << "�������� �������: ";
    cout << i2 + 1;
    for (int c = 0; c < n; c++) {
        for (int j = 0; j < n; j++) {
            if (a[i2][j] == -2) {
                cout << " -> " << j + 1;
                i2 = j;
                break;
            }
        }
    }

    cout << endl;
    return 0;
}
