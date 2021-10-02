// Лабораторная работа №2 
// Выполнили студенты группы м3о-219Бк-20 Бокарев, Катвалян

#include <iostream>
#include <stdio.h>
#include <fstream>
#include<chrono> // подключение библиотеки для вычисления времени работы алгоритмов 

#define NotFound -1;
using namespace std;

void FillRand(int* arr, int n, double min, double max); // Функция, формирующая рандомную последовательность
void FillRand(char* arr, int n, double min, double max); // Функция, формирующая рандомную последовательность
void FillGrow(int* arr, int length, int min, int max); // Функция, формирующая возрастающую последовательность
void FillGrow(char* arr, int length, int min, int max); // Функция, формирующая возрастающую последовательность
void Writer(int* A, int length); // Функция, печатающая последовательность
void Writer(char* A, int length); // Функция, печатающая последовательность
int QSearch(int *A, int x, int n); // Функция быстрого последовательного поиска в лекциях Sentinel_Linear_Search 
int SSearch(int* A, int x, int n); // Функция последовательного поиска в лекциях Better_Linear_Search
int TSearch(int* A, int x, int n); // Функция последовательного поиска в упорядоченном массиве
int BSearch(int* A, int x, int n); // Функция бинарного поиска
int QSearch(char* A, char x, int n); // Функция быстрого последовательного поиска в лекциях Sentinel_Linear_Search 
int SSearch(char* A, char x, int n); // Функция последовательного поиска в лекциях Better_Linear_Search
int TSearch(char* A, char x, int n); // Функция последовательного поиска в упорядоченном массиве
int BSearch(char* A, char x, int n); // Функция бинарного поиска


int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int n = 0;
    cout << "Введите размер последовательности: "; cin >> n;
    /*int* arr = new int[n];
    FillRand(arr, n, 0, 50);*/
    int* arrGrow = new int[n + 1];
    cout << "Возрастающая последовательность" << endl;
    FillGrow(arrGrow, n - 1, 1, 30);
    arrGrow[n] = INT_MAX;

    int k;

    int (*LineralOperations[4])(int*, int, int) = { QSearch, SSearch, TSearch, BSearch }; // Указатель на массив функций
    
    int lengthLin = sizeof(LineralOperations) / sizeof(LineralOperations[0]);// получаем длину массива
    for (int i = 0; i < lengthLin; i++)
    {
        for (int j = 0; j < 3; j++) {
            if (j == 0) k = arrGrow[0]; // ключ поиска
            else if (j == 1) k = arrGrow[n / 2]; // ключ поиска
            else if (j == 2) k = arrGrow[n]; // ключ поиска
            auto begin = chrono::steady_clock::now(); // получаем время перед началом формирования последовательности

            int temp = LineralOperations[i](&arrGrow[0], k, n);    // вызов функции по указателю
            
            auto end = chrono::steady_clock::now();// получаем время по окончанию формирования последовательности

            auto elapsed_ms = chrono::duration_cast<chrono::microseconds>(end - begin);// получаем время работы в микросекундах

            cout << elapsed_ms.count() << endl;
        }
    }

   
    /*int result = QSearch(&arrGrow[0], k, n);
    if (result >= 0) {
        cout << "Процедура Q индекс равен: " << result << endl;
    }
    else {
        cout << "Процедура Q элемент не найден" << endl;
    }


    result = SSearch(&arrGrow[0], k, n);
    if (result >= 0) {
        cout << "Процедура S индекс равен: " << result << endl;
    }
    else {
        cout << "Процедура S элемент не найден" << endl;
    }

    // Процедура T
    cout << "Введите ключ поиска: "; cin >> k;
    
    result = TSearch(&arrGrow[0], k, n);
    if (result >= 0) {
        cout << "Процедура T индекс равен: " << result << endl;
    }
    else {
        cout << "Процедура T элемент не найден" << endl;
    }

    //Процедура B
    result = BSearch(&arrGrow[0], k, n);
    if (result >= 0) {
        cout << "Процедура B индекс равен: " << result << endl;
    }
    else {
        cout << "Процедура B элемент не найден" << endl;
    }
    */

    cout << "Введите размер символьной последовательности: "; cin >> n;
    /*char* arrChar = new char[n];
    for (int i = 0; i < n; i++) {
        cout << "Введите элемент символ: "; cin >> arrChar[i];
        
    }
    Writer(&arrChar[0], n);*/

    char* arrGrowChar = new char[n];
    cout << "Возрастающая последовательность символов" << endl;
    FillGrow(arrGrowChar, n - 1, 1, 30);
    arrGrowChar[n] = INT_MAX;

    char key; //cout << "Введите ключ поиска: "; cin >> key;

    int (*CharSearch[4])(char*, char, int) = { QSearch, SSearch, TSearch, BSearch }; // Указатель на массив функций

    int lengthLinChar = sizeof(CharSearch) / sizeof(CharSearch[0]);// получаем длину массива
    for (int i = 0; i < lengthLinChar; i++)
    {
        for (int j = 0; j < 3; j++) {
            if (j == 0) key = arrGrowChar[0]; // ключ поиска
            else if (j == 1) key = arrGrowChar[n / 2]; // ключ поиска
            else if (j == 2) key = arrGrowChar[n - 1]; // ключ поиска
            auto begin = chrono::steady_clock::now(); // получаем время перед началом формирования последовательности

            CharSearch[i](arrGrowChar, k, n);    // вызов функции по указателю

            auto end = chrono::steady_clock::now();// получаем время по окончанию формирования последовательности

            auto elapsed_ms = chrono::duration_cast<chrono::microseconds>(end - begin);// получаем время работы в микросекундах

            cout << elapsed_ms.count() << endl;
        }
    }


    /*
    int result = QSearch(&arrGrowChar[0], key, n);
    if (result >= 0) {
        cout << "Процедура Q индекс равен: " << result << endl;
    }
    else {
        cout << "Процедура Q элемент не найден" << endl;
    }
    result = SSearch(&arrGrowChar[0], key, n);
    if (result >= 0) {
        cout << "Процедура S индекс равен: " << result << endl;
    }
    else {
        cout << "Процедура S элемент не найден" << endl;
    }
    
    // Процедура T
    
    
    cout << "Введите ключ поиска: "; cin >> key;

    result = TSearch(&arrGrowChar[0], key, n);
    if (result > 0) {
        cout << "Процедура T индекс равен: " << result << endl;
    }
    else {
        cout << "Процедура T элемент не найден" << endl;
    }

    //Процедура B
    result = BSearch(&arrGrowChar[0], key, n);
    if (result > 0) {
        cout << "Процедура B индекс равен: " << result << endl;
    }
    else {
        cout << "Процедура B элемент не найден" << endl;
    }
    */
}
void FillGrow(char* arr, int length, int min, int max) {
    int step = 1 + (max - min) / length;

    for (int i = 0; i < length; i++) {
        arr[i] = (char) (min + step * i);
    }
    arr[length + 1] = INT_MAX;
    Writer(arr, length);
}
void FillGrow(int* arr, int length, int min, int max) {
    int step = 1 + (max - min) / length;

    for (int i = 0; i < length; i++) {
        arr[i] = min + step * i;
    }
    arr[length + 1] = INT_MAX;
    Writer(arr, length);
}
int TSearch(int* A, int x, int n) {
    int count = 0;
    int i = 0;

    while (x > A[i]) {
        i++;
        count++;
    }
    cout << "Количество операций сравнения для TSearch " << count << endl;
    if (x == A[i]) return i;
    else return NotFound;
}
int BSearch(int* A, int k, int n) {
    /*int count = 0;
    int low = 0;
    int high = n;
    int mid = (low + high) / 2;
    if (A[mid] == k) {
        cout << "Количество операций сравнения для BSearch " << count << endl;
        return mid;
    } 
    while (A[mid] <= k) {
        count++;

        if (A[mid] == k) {
            cout << "Количество операций сравнения для BSearch " << count << endl;
            return mid;
        }
        low = mid;
        mid = (low + high) / 2;
        
    }
    while (A[mid] >= k) {
        count++;
        if (A[mid] == k) {
            cout << "Количество операций сравнения для BSearch " << count << endl;
            return mid;
        }
        high = mid;
        mid = (low + high) / 2;
        
    }
    return NotFound;*/
    bool flag = false;
    int l = 0; // левая граница
    int r = 9; // правая граница
    int mid;

    while ((l <= r) && (flag != true)) {
        mid = (l + r) / 2; // считываем срединный индекс отрезка [l,r]

        if (A[mid] == k) flag = true; //проверяем ключ со серединным элементом
        if (A[mid] > k) r = mid - 1; // проверяем, какую часть нужно отбросить
        else l = mid + 1;
    }

    if (flag) {
        cout << "Индекс элемента " << k << " в массиве равен: " << mid;
        return mid;
    }
    else cout << "Извините, но такого элемента в массиве нет";
    return NotFound;

}
int QSearch(int* A, int x, int n) {
    int count = 0;
    int Last = A[n];
    A[n] = x;

    int i = 0;
    for (i; A[i] != x; i++) {
        count++;
    }
    A[n] = Last;
    if (i < n || A[n] == x) {
        cout << "Количество операций сравнения для QSearch " << count << endl;
        return i;
    }
    else {
        cout << "Количество операций сравнения для QSearch " << count << endl;
        return NotFound;
    }
}
int SSearch(int* A, int x, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        count++;
        if (A[i] == x) {
            cout << "Количество операций сравнения для SSearch " << count << endl;
            return i;
        }
        if (A[i] == A[n - 1]) {
            cout << "Количество операций сравнения для SSearch " << count << endl;
            return NotFound;
        }
    }
}

int TSearch(char* A, char x, int n) {
    int count = 0;
    int i = 0;

    while (x > A[i]) {
        i++;
        count++;
    }
    cout << "Количество операций сравнения для TSearch " << count << endl;
    if (x == A[i]) return i;
    else return NotFound;
}
int BSearch(char* A, char k, int n) {
    int count = 0;
    int low = 0;
    int high = n - 1;
    int mid = (low + high) / 2;
    if (A[mid] == k) {
        cout << "Количество операций сравнения для BSearch " << count << endl;
        return mid;
    }
    while (A[mid] <= k) {
        count++;

        if (A[mid] == k) {
            cout << "Количество операций сравнения для BSearch " << count << endl;
            return mid;
        }
        low = mid;
        mid = (low + high) / 2;

    }
    while (A[mid] >= k) {
        count++;
        if (A[mid] == k) {
            cout << "Количество операций сравнения для BSearch " << count << endl;
            return mid;
        }
        high = mid;
        mid = (low + high) / 2;

    }
    return NotFound;
}
int QSearch(char* A, char x, int n) {
    int count = 0;
    int Last = A[n];
    A[n] = x;

    int i = 0;
    for (i; (int)A[i] != (int)x; i++) {
        //cout << "Символ A[i] " << (int)A[i] << " символ x "<< (int)x << endl;
        count++;
    }
    A[n] = Last;
    if (i < n || A[n] == x) {
        cout << "Количество операций сравнения для QSearch " << count << endl;
        return i;
    }
    else {
        cout << "Количество операций сравнения для QSearch " << count << endl;
        return NotFound;
    }
}
int SSearch(char* A, char x, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        count++;
        if ((int)A[i] == (int) x) {
            cout << "Количество операций сравнения для SSearch " << count << endl;
            return i;
        }
        if ((int)A[i] == (int)A[n - 1]) {
            cout << "Количество операций сравнения для SSearch " << count << endl;
            return NotFound;
        }
    }
}

void FillRand(int* arr, int n, double min, double max) {
    for (int i = 0; i < n; i++) {
        arr[i] = 10 + ((double)rand() / RAND_MAX) * (max - min);
    }
    
    Writer(arr, n);
}

void FillRand(char* arr, int n, double min, double max) {
    for (int i = 0; i < n; i++) {
        arr[i] = (char)(10 + ((double)rand() / RAND_MAX) * (max - min));
    }

    Writer(arr, n);
}

void Writer(int* A, int length) {
    for (int i = 0; i < length; i++) {
        cout << "arr[" << i << "] = " << A[i] << endl;
    }
}
void Writer(char* A, int length) {
    for (int i = 0; i < length; i++) {
        cout << "arr[" << i << "] = " << A[i] << endl;
    }
}

