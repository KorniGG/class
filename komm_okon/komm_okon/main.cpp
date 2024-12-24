#include <windows.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <sstream>
#include <string>
#include <windows.h>

using namespace std;

const int nm = 5;
vector<vector<int>> a;
int n;
HWND hwndDisplay;
HWND hwndButtonNext;
HWND hwndButtonExit;
HWND hwndTextRoute;
HINSTANCE hInst;
int currentStep = 0;
vector<wstring> matrixSteps;  // Используем wstring для хранения строк с матрицами
wstring routeOutput;  // Используем wstring для широких строк

void displayMatrix(HWND hwnd, const vector<vector<int>>& matrix) {
    wstringstream ss;
    ss << L"Текущая матрица:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == -1)
                ss << L" -1 ";
            else if (matrix[i][j] == -2)
                ss << L" -2 ";
            else
                ss << matrix[i][j] << L" ";
        }
        ss << L"\n";
    }
    SetWindowText(hwnd, ss.str().c_str());  // Используем wide string
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

    // Запоминаем текущий шаг
    wstringstream ss;
    ss << L"После применения makeBase(" << ik + 1 << L", " << jk + 1 << L"):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == -1)
                ss << L" -1 ";
            else if (a[i][j] == -2)
                ss << L" -2 ";
            else
                ss << a[i][j] << L" ";
        }
        ss << L"\n";
    }
    matrixSteps.push_back(ss.str());  // Используем wide string
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    static int stepIndex = 0;

    switch (msg) {
    case WM_CREATE:
        // Чтение матрицы из файла
    {
        ifstream f("mx.txt");
        if (!f) {
            cerr << "Ошибка: Не удалось открыть файл mx.txt!" << endl;
            return 1;
        }

        f >> n;
        a.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                f >> a[i][j];

        f.close();

        // Инициализация диагональных элементов
        for (int i = 0; i < n; i++)
            a[i][i] = -1;

        // Инициализация кнопок
        hwndDisplay = CreateWindowEx(0, L"STATIC", L"", WS_CHILD | WS_VISIBLE | SS_LEFT, 20, 50, 600, 400, hwnd, NULL, hInst, NULL);
        hwndButtonNext = CreateWindow(L"BUTTON", L"Далее", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 20, 460, 100, 30, hwnd, (HMENU)1, hInst, NULL);
        hwndButtonExit = CreateWindow(L"BUTTON", L"Выход", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 130, 460, 100, 30, hwnd, (HMENU)2, hInst, NULL);
        hwndTextRoute = CreateWindowEx(0, L"STATIC", L"", WS_CHILD | WS_VISIBLE | SS_LEFT, 20, 500, 600, 30, hwnd, NULL, hInst, NULL);
    }

    // Отображаем начальную матрицу
    displayMatrix(hwndDisplay, a);

    break;

    case WM_COMMAND:
        if (LOWORD(wp) == 1) {  // Кнопка "Далее"
            if (stepIndex < matrixSteps.size()) {
                // Отображаем шаг
                SetWindowText(hwndDisplay, matrixSteps[stepIndex].c_str());
                stepIndex++;
            }
            else {
                // Если шаги закончились, начинаем решение задачи
                if (currentStep == 0) {
                    // Инициализация шагов
                    for (int c = 0; c < n; c++) {
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

                        // Вычитаем минимальные элементы из строк
                        for (int i = 0; i < n; i++) {
                            int minv = INT_MAX;
                            for (int j = 0; j < n; j++)
                                if (a[i][j] >= 0 && a[i][j] < minv)
                                    minv = a[i][j];

                            for (int j = 0; j < n; j++)
                                if (a[i][j] >= 0)
                                    a[i][j] -= minv;
                        }

                        // Запоминаем текущий шаг
                        makeBase(i2, j2);
                    }
                    // Отображаем маршрут
                    routeOutput = L"Итоговый маршрут: ";
                    int i2 = 0;
                    routeOutput += to_wstring(i2 + 1);
                    for (int c = 0; c < n; c++) {
                        for (int j = 0; j < n; j++) {
                            if (a[i2][j] == -2) {
                                routeOutput += L" -> " + to_wstring(j + 1);
                                i2 = j;
                                break;
                            }
                        }
                    }
                    SetWindowText(hwndTextRoute, routeOutput.c_str());
                }
                currentStep++;
            }
        }

        if (LOWORD(wp) == 2) {  // Кнопка "Выход"
            PostMessage(hwnd, WM_CLOSE, 0, 0);
        }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hwnd, msg, wp, lp);
    }

    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASSEX wc;
    HWND hwnd;
    MSG msg;

    hInst = GetModuleHandle(NULL);
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInst;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = L"TSPWindowClass";  // Используем широкую строку
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    if (!RegisterClassEx(&wc)) {
        MessageBox(NULL, L"Window class creation failed!", L"Error", MB_ICONEXCLAMATION | MB_OK);  // Используем широкую строку
        return 0;
    }

    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        L"TSPWindowClass",  // Используем широкую строку
        L"Задача коммивояжера",  // Используем широкую строку
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 640, 600,
        NULL, NULL, hInst, NULL);

    if (hwnd == NULL) {
        MessageBox(NULL, L"Window creation failed!", L"Error", MB_ICONEXCLAMATION | MB_OK);  // Используем широкую строку
        return 0;
    }

    ShowWindow(hwnd, SW_SHOW);
    UpdateWindow(hwnd);

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
