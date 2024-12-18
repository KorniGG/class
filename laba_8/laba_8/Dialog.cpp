#include "Dialog.h"

// Конструктор Dialog, наследующийся от List
Dialog::Dialog(void) : List() {
    EndState = 0;
}

// Деструктор Dialog
Dialog::~Dialog(void) {}

// Получение события от пользователя
void Dialog::GetEvent(TEvent& event) {
    string OpInt = "m+-szq"; // Строка содержит коды операций
    string s;
    char code;
    cout << '>';
    cin >> s;
    code = s[0]; // Первый символ команды

    // Проверяем, является ли символ кодом операции
    if (OpInt.find(code) >= 0) {
        event.what = evMessage;
        switch (code) {
        case 'm': event.command = cmMake; break; // Создать группу
        case '+': event.command = cmAdd; break; // Добавить объект в группу
        case '-': event.command = cmDel; break; // Удалить объект из группы
        case 's': event.command = cmShow; break; // Просмотр группы
        case 'z': event.command = cmGet; break; // Получить имя
        case 'q': event.command = cmQuit; break; // Конец работы
        }
    }
    else {
        event.what = evNothing; // Пустое событие
    }
}

// Основной цикл выполнения диалога
void Dialog::Execute() {
    TEvent event;
    do {
        EndState = 0;
        GetEvent(event); // Получить событие
        HandleEvent(event); // Обработать событие
    } while (Valid());
}

// Проверка состояния диалога
bool Dialog::Valid() {
    return EndState == 0;
}

// Очистка события
void Dialog::ClearEvent(TEvent& event) {
    event.what = evNothing; // Пустое событие
}

// Завершение выполнения диалога
void Dialog::EndExec() {
    EndState = 1;
}

// Обработчик событий
void Dialog::HandleEvent(TEvent& event) {
    if (event.what == evMessage) {
        switch (event.command) {
        case cmMake: // Создание группы
            cout << "Введите размер: ";
            cin >> size;
            beg = new Object * [size]; // Выделяем память под массив указателей
            cur = 0; // Текущая позиция
            ClearEvent(event); // Очищаем событие
            break;
        case cmAdd: // Добавление объекта
            Add();
            ClearEvent(event);
            break;
        case cmDel: // Удаление объекта
            Del();
            ClearEvent(event);
            break;
        case cmShow: // Просмотр группы
            Show();
            ClearEvent(event);
            break;
        case cmQuit: // Выход
            EndExec();
            ClearEvent(event);
            break;
        case cmGet: // Получить имена
            Get_Name();
            ClearEvent(event);
            break;
        };
    };
}
