// Лабораторная работа №2 
// Выполнили студенты группы м3о-219Бк-20 Бокарев, Катвалян

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int n = 0;
    cout << "Введите размер последовательности: ";
    cin >> n;
    int* arr = new int[n];
    FillRand(arr, n, 1, 30);
    
    
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

        printf("%3.3f\n", A[i]);
        cout << "arr[" << i << "] = \t" << A[i] << endl;
        //File << "arr[" << i << "] = \t" << A[i] << endl;
    }
}