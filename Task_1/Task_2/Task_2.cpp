#include <iostream>
#include <ctime>
using namespace std;

struct Stack
{
    double data;
    Stack* next;
};

Stack* top = NULL;
int const INF = 1e9;

Stack* push(int input) {
    Stack* newEl = new Stack;
    newEl->data = input;
    newEl->next = top;
    top = newEl;
    return newEl;
}

void show() {
    Stack* currentEl = top;
    while (currentEl != NULL)
    {
        cout << currentEl->data << endl;
        currentEl = currentEl->next;
    }
}

void pop() {
    Stack* temp = top->next;
    cout << "Объект " << top->data << " удален" << endl;
    delete top;
    top = temp;
}

void cleanStack() {
    while (top != NULL)
    {
        pop();
    }
}

void variant11() {
    if (top == NULL)
    {
        cout << "СТЕК пуст! Выполнение функции невозможно." << endl;
        return;
    }
    Stack* currentEl = top;
    double summa = 0;
    int counter = 0;
    while (currentEl != NULL)
    {
        counter++;
        summa += currentEl->data;
        currentEl = currentEl->next;
    }
    double mid = summa / counter;
    top->data = mid;
}

void addressSort() {
    Stack* t = NULL, * t1, * temp;
    push(INF);
    if (top->next->next == NULL) return;
    do {
        for (t1 = top; t1->next->next != t; t1 = t1->next) {
            if (t1->next->data > t1->next->next->data) {
                temp = t1->next->next;
                t1->next->next = temp->next;
                temp->next = t1->next;
                t1->next = temp;
            }
        }
        t = t1->next;
    } while (top->next->next != t);
    pop();
}

void dataSort() {
    Stack* t = NULL;
    Stack* t1;
    double temp;
    do {
        for (t1 = top; t1->next != t; t1 = t1->next) {
            if (t1->data > t1->next->data) {
                temp = t1->data;
                t1->data = t1->next->data;
                t1->next->data = temp;
            }
        }
        t = t1;
    } while (top->next != t);
}

int main()
{
    setlocale(0, "Rus");
    srand(time(NULL));

    while (true) {
        cout << "1. Создание " << endl
            << "2. Добавление" << endl
            << "3. Просмотр" << endl
            << "4. Удалить вершину" << endl
            << "5. Очистить" << endl
            << "6. Индивидуальное задание" << endl
            << "7. Сортировка элементов СТЕКа" << endl
            << "0. Выход" << endl;
        int menu;
        cin >> menu;
        cout << endl;
        switch (menu) {
        case 1: case 2:
            if (menu == 1 && top != NULL) {
                cout << "Для создание очистите память!" << endl;
                break;
            }
            cout << "Введите количество элементов СТЕКа: ";
            int elCount;
            cin >> elCount;
            for (int i = 0; i < elCount; i++) {
                int element;
                element = rand() % 50 - 25;
                top = push(element);
            }
            if (menu == 1) {
                cout << "Создан СТЕК на " << elCount << " элементов" << endl;
            }
            else {
                cout << "В СТЕК добавлено " << elCount << " элементов" << endl;
            }
            cout << endl;
            break;

        case 3:
            if (!top) {
                cout << "СТЕК пуст!" << endl;
                cout << endl;
                break;
            }
            cout << "--- СТЕК ---" << endl;
            show();
            cout << endl;
            break;

        case 4:
            if (top != NULL) {
                pop();
                cout << "Вершина удалена!" << endl;
            }
            else {
                cout << "СТЕК пуст! Удаление невозможно..." << endl;
            }
            cout << endl;
            break;

        case 5:
            if (top != NULL) {
                cleanStack();
                cout << "Память очищена!" << endl;
            }
            else {
                cout << "СТЕК пуст! Удаление невозможно..." << endl;
            }
            cout << endl;
            break;

        case 6:
            variant11();
            cout << "Первый элемент заменен на среднее арифметичкое!" << endl << endl;
            break;

        case 7:
            if (top == NULL)
            {
                cout << "СТЕК пуст! Сортировка невозможна..." << endl << endl;
                break;
            }
            cout << "Выберите вариант сортировки: " << endl
                << "1. Обмен адресами" << endl
                << "2. Обмен информацией" << endl;
            int menu;
            cin >> menu;
            cout << endl;
            switch (menu)
            {
            case 1:
                addressSort();
                cout << "Сортировка выполнена!" << endl;
                break;
            case 2:
                dataSort();
                cout << "Сортировка выполнена!" << endl;
                break;
            default:
                cout << "Такого варианта нет!" << endl;
                break;
            }
            cout << endl;
            break;

        case 0:
            if (top != NULL) cleanStack();
            return 0;
        }
    }
}