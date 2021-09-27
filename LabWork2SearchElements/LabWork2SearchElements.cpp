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
int TSearch(int* A, int x, int n);
int BSearch(int* A, int x, int n);


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
    

    
    int result1 = linearSearch(&arr[0], k, n);
    if (result1 > 0) {
        cout << "Процедура S индекс равен: " << result1 << endl;
    }
    else {
        cout << "Процедура S лемент не найден" << endl;
    }
    int result2 = bLinearSearch(&arr[0], k, n);
    if (result2 > 0) {
        cout << "Процедура Q индекс равен: " << result1 << endl;
    }
    else {
        cout << "Процедура Q элемент не найден" << endl;
    }
    
    

    // Процедура T
    int* arrGrow = new int[n+1];
    cout << "Возрастающая последовательность" << endl;
    FillGrow(arrGrow, n, 1, 30);
    cout << "Введите ключ поиска: "; cin >> k;
    
    result2 = TSearch(&arrGrow[0], k, n);
    if (result2 > 0) {
        cout << "Процедура T индекс равен: " << result1 << endl;
    }
    else {
        cout << "Процедура T элемент не найден" << endl;
    }

    //Процедура B
    result2 = BSearch(&arrGrow[0], k, n);
    if (result2 > 0) {
        cout << "Процедура B индекс равен: " << result1 << endl;
    }
    else {
        cout << "Процедура B элемент не найден" << endl;
    }
}
void FillGrow(int* arr, int length, int min, int max) {
    int step = 1 + (max - min) / length;

    for (int i = 0; i < length; i++) {

        arr[i] = min + step * i;

    }
    arr[length + 1] = INT_MAX;
    //File << "Возрастающая последовательность целых чисел" << endl;
    Writer(arr, length);
}
int TSearch(int* A, int x, int n) {
    int i = 0;

    while (x > A[i]) {
        i++;
    }
    if (x == A[i]) return i;
    else return NotFound;
}
int BSearch(int* A, int k, int n) {
    int low = 0;
    int high = n - 1;
    int mid = (low + high) / 2;
    if (A[mid] == k) {
        return mid;
    } 
    while (A[mid] <= k) {
        if (A[mid] == k) {
            return mid;
        }
        low = mid;
        mid = (low + high) / 2;
        
    }
    while (A[mid] >= k) {
        if (A[mid] == k) {
            return mid;
        }
        high = mid;
        mid = (low + high) / 2;
        
    }
    return NotFound;
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

