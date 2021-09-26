// Лабораторная работа №2 
// Выполнили студенты группы м3о-219Бк-20 Бокарев, Катвалян

#include <iostream>
#include <stdio.h>
#include <fstream>

#define NotFound -1;
using namespace std;

void FillRand(int* arr, int n, double min, double max);
void FillGrow(int* arr, int length, int min, int max);
void Writer(int* A, int length);
int linearSearch(int *A, int x, int n);
int bLinearSearch(int* A, int x, int n);

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int n = 0;
    cout << "Введите размер последовательности: "; cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 50;
    }
    Writer(&arr[0], n);
    int k; cout << "Введите ключ поиска: "; cin >> k;
    /*FillGrow(arr, n, 1, 30);
    int i = 0;
    int k = arr[5]; //ключ поиска
    while (k > arr[i]) {
        i++;
    }
    if (k == arr[i]) cout << "Индекс i = " << i << endl;
    else cout << "Элемент не найден";
    */
    int result1 = linearSearch(&arr[0], k, n);
    if (result1 > 0) {
        cout << "Индекс равен: " << result1 << endl;
    }
    else {
        cout << "Элемент не найден" << endl;
    }
    int result2 = bLinearSearch(&arr[0], k, n);
    if (result2 > 0) {
        cout << "Индекс равен: " << result1 << endl;
    }
    else {
        cout << "Элемент не найден" << endl;
    }
}
void FillGrow(int* arr, int length, int min, int max) {
    int step = 1 + (max - min) / length;

    for (int i = 0; i < length; i++) {

        arr[i] = min + step * i;

    }
    //File << "Возрастающая последовательность целых чисел" << endl;
    Writer(arr, length);
}

int linearSearch(int* A, int x, int n) {
    int Last = A[n];
    A[n] = x;

    int i = 0;
    for (i; A[i] != x; i++);
    A[n] = Last;
    if (i < n || A[n] == x) {
        return i;
    }
    else {
        return NotFound;
    }
}
int bLinearSearch(int* A, int x, int n) {
    for (int i = 0; i < n; i++) {
        if (A[i] == x) {
            return i;
        }
        if (A[i] == A[n - 1]) {
            return NotFound;
        }
    }
}




void FillRand(int* arr, int n, double min, double max) {
    for (int i = 0; i < n; i++) {

        arr[i] = 10 + ((double)rand() / RAND_MAX) * (max - min);
    }
    //File << "Рандомная последовательность дробных чисел" << endl;
    Writer(arr, n);
}
void Writer(int* A, int length) {
    for (int i = 0; i < length; i++) {

        //printf("%3.3d\n", A[i]);

        cout << "arr[" << i << "] = " << A[i] << endl;
        //File << "arr[" << i << "] = \t" << A[i] << endl;
    }
}

