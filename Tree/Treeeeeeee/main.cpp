#include <iostream>
#include "tree.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int k;

    cout << "������� ���������� ����� ��������� ������: ";
    cin >> k;

    Tree<int>* CurTree = new Tree<int>(0);
    CurTree = CurTree->balanced(k);

    cout << "������ � �������������� ���� (����������������):" << endl;
    CurTree->print_horizontal();

    // ������� ���������� �������
    int leaf_count = CurTree->count_leaves();
    cout << "���������� ������� � ������: " << leaf_count << endl;

    // �������������� � ������ ������
    CurTree->to_search_tree();

    cout << "������ � �������������� ���� (�����):" << endl;
    CurTree->print_horizontal();



    delete CurTree;
    return 0;
}
