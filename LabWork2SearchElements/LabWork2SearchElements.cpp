// Лабораторная работа №2 
// Выполнили студенты группы м3о-219Бк-20 Бокарев, Катвалян

#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

void FillGrow(int* arr, int length, int min, int max);
void Writer(int* A, int length);

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int n = 0;
    cout << "Введите размер последовательности: ";
    cin >> n;
    int* arr = new int[n];

    FillGrow(arr, n, 1, 30);
    int i = 0;
    int k = arr[5]; //ключ поиска
    while (k > arr[i]) {
        i++;
    }
    if (k == arr[i]) cout << "Индекс i = " << i << endl;
    else cout << "Элемент не найден";
    
    
}
void FillGrow(int* arr, int length, int min, int max) {
    int step = 1 + (max - min) / length;

    for (int i = 0; i < length; i++) {

        arr[i] = min + step * i;

    }
    //File << "Возрастающая последовательность целых чисел" << endl;
    Writer(arr, length);
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

        cout << "arr[" << i << "] = \t" << A[i] << endl;
        //File << "arr[" << i << "] = \t" << A[i] << endl;
    }
}