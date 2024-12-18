#include <iostream>
#include "tree.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int k;

    cout << "Введите количество узлов бинарного дерева: ";
    cin >> k;

    Tree<int>* CurTree = new Tree<int>(0);
    CurTree = CurTree->balanced(k);

    cout << "Дерево в горизонтальном виде (сбалансированное):" << endl;
    CurTree->print_horizontal();

    // Подсчет количества листьев
    int leaf_count = CurTree->count_leaves();
    cout << "Количество листьев в дереве: " << leaf_count << endl;

    // Преобразование в дерево поиска
    CurTree->to_search_tree();

    cout << "Дерево в горизонтальном виде (поиск):" << endl;
    CurTree->print_horizontal();



    delete CurTree;
    return 0;
}
