#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <fstream>
using namespace std;

template <class T>
class Tree {
private:
    Tree<T>* left;
    Tree<T>* right;
    Tree<T>* parent;
    T data;

public:
    Tree(T value, Tree<T>* parent = nullptr) {
        this->right = nullptr;
        this->left = nullptr;
        this->parent = parent;
        this->data = value;
    }

    Tree() : left(nullptr), right(nullptr), parent(nullptr) {}

    ~Tree() {
        delete_left();
        delete_right();
    }

    void delete_left() {
        if (left != nullptr) {
            left->delete_left();
            left->delete_right();
            delete left;
            left = nullptr;
        }
    }

    void delete_right() {
        if (right != nullptr) {
            right->delete_left();
            right->delete_right();
            delete right;
            right = nullptr;
        }
    }

    T get_data() const {
        return data;
    }

    Tree<T>* get_left() const {
        return left;
    }

    Tree<T>* get_right() const {
        return right;
    }

    Tree<T>* get_parent() const {
        return parent;
    }

    void insert_right(T data) {
        Tree<T>* new_node = new Tree(data);
        if (this->right != nullptr) {
            this->right->parent = new_node;
            new_node->right = this->right;
        }
        this->right = new_node;
        new_node->parent = this;
    }

    void insert_left(T data) {
        left = new Tree<T>(data);
        left->parent = this;
    }

    void insert(T data) {
        Tree<T>* current = this;
        while (current != nullptr) {
            if (data > current->data) {
                if (current->right != nullptr) {
                    current = current->right;
                } else {
                    current->insert_right(data);
                    return;
                }
            } else if (data < current->data) {
                if (current->left != nullptr) {
                    current = current->left;
                } else {
                    current->insert_left(data);
                    return;
                }
            } else {
                return; // Duplicate data
            }
        }
    }

    void direct_way(Tree<T>* current_tree) const {
        if (current_tree == nullptr) {
            return;
        }
        cout << current_tree->get_data() << " ";
        direct_way(current_tree->get_left());
        direct_way(current_tree->get_right());
    }

    void symmetric_way(Tree<T>* current_tree) const {
        if (current_tree != nullptr) {
            symmetric_way(current_tree->left);
            cout << current_tree->data << " ";
            symmetric_way(current_tree->right);
        }
    }

    void reverse_way(Tree<T>* current_tree) const {
        if (current_tree != nullptr) {
            reverse_way(current_tree->left);
            reverse_way(current_tree->right);
            cout << current_tree->data << " ";
        }
    }

    void print_horizontal(int depth = 0, char br = ' ') const {
        if (right != nullptr) {
            right->print_horizontal(depth + 1, '/');
        }
        for (int i = 0; i < depth; ++i) {
            cout << "   ";
        }
        cout << br << "--" << data << endl;
        if (left != nullptr) {
            left->print_horizontal(depth + 1, '\\');
        }
    }

    int get_height() const {
        if (this == nullptr) return 0;
        int h1 = left ? left->get_height() : 0;
        int h2 = right ? right->get_height() : 0;
        return max(h1, h2) + 1;
    }

    int get_nodes_cnt() const {
        if (this == nullptr) return 0;
        int l = left ? left->get_nodes_cnt() : 0;
        int r = right ? right->get_nodes_cnt() : 0;
        return l + r + 1;
    }

    int count_leaves() const {
        if (!this) return 0; // Если узел пустой, листьев нет
        if (!left && !right) return 1; // Узел является листом
        int left_count = left ? left->count_leaves() : 0; // Рекурсивный подсчет в левом поддереве
        int right_count = right ? right->count_leaves() : 0; // Рекурсивный подсчет в правом поддереве
        return left_count + right_count; // Сумма листьев в левом и правом поддеревьях
    }

    void fill_empty(int level) {
        if (level == 1) {
            return;
        }
        if (!right) {
            insert_right(-1);
        }
        if (!left) {
            insert_left(-1);
        }
        right->fill_empty(level - 1);
        left->fill_empty(level - 1);
    }

    void print_vertical() {
        Tree<T>* tree1 = copy();
        int height = tree1->get_height();
        tree1->fill_empty(height);

        queue<Tree<T>*> q;
        q.push(tree1);
        vector<T> values;

        while (!q.empty()) {
            Tree<T>* node = q.front();
            q.pop();

            if (node) {
                values.push_back(node->data);
                q.push(node->left);
                q.push(node->right);
            } else {
                values.push_back(-1);
            }
        }

        int level_width = pow(2, height) - 1;
        int index = 0;

        for (int level = 0; level < height; ++level) {
            int nodes_on_level = pow(2, level);
            int space_between = level_width / nodes_on_level;

            for (int i = 0; i < nodes_on_level; ++i) {
                if (i == 0) {
                    cout << string(space_between / 2, ' ');
                } else {
                    cout << string(space_between, ' ');
                }
                if (values[index] != -1) {
                    cout << values[index];
                } else {
                    cout << " ";
                }
                ++index;
            }
            cout << endl;
        }
    }

    void to_search_tree() {
        vector<T> elements;
        collect_elements(this, elements);  // Собираем элементы в массив
        sort(elements.begin(), elements.end()); // Сортируем элементы
        clear_tree(); // Удаляем старое дерево
        for (const auto& elem : elements) {
            insert(elem); // Вставляем элементы в дерево поиска
        }
    }

    // Вспомогательный метод для сбора элементов дерева
    void collect_elements(Tree<T>* node, vector<T>& elements) {
        if (!node) return;
        elements.push_back(node->data);
        if (node->left) collect_elements(node->left, elements);
        if (node->right) collect_elements(node->right, elements);
    }

    // Вспомогательный метод для очистки дерева
    void clear_tree() {
        delete_left();
        delete_right();
        left = nullptr;
        right = nullptr;
    }

    Tree<T>* balanced(int count) {
        if (count <= 0) return nullptr;
        T value;
        cout << "Введите данные для узла дерева: ";
        cin >> value;

        Tree<T>* root = new Tree<T>(value);
        root->left = balanced(count / 2);
        if (root->left) root->left->parent = root;
        root->right = balanced(count - count / 2 - 1);
        if (root->right) root->right->parent = root;
        return root;
    }



    Tree<T>* copy() const {
        Tree<T>* new_tree = new Tree<T>(data);
        if (left != nullptr) {
            new_tree->left = left->copy();
            new_tree->left->parent = new_tree;
        }
        if (right != nullptr) {
            new_tree->right = right->copy();
            new_tree->right->parent = new_tree;
        }
        return new_tree;
    }
};