#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <class T>
class GnomeSort {
private:
    
	T* arr;   //массив для сортировки
	int size;  //размер массива

public:
	
    // для массива
    GnomeSort(T* a, int n) {
        this->size = n;
        arr = new T[n];
        for (int i = 0; i < n; i++) {
            this->arr[i] = a[i];
        }
    }

    // для вектора
    GnomeSort(vector<T> a, int n) {
        this->size = n;
        arr = new T[n];
        for (int i = 0; i < n; i++) {
            this->arr[i] = a[i];
        }
    }
   
	// сортировка
    void Sort() {
        int index = 1; 

        while (index < size) {
            if (arr[index - 1] < arr[index]) //для сортировки по убыванию поменяйте знак сравнения на >=
            {
                index++;
            }
            else
            {
                swap(arr[index - 1], arr[index]);
                index--;
                if (index == 0)
                {
                    index++;
                }

            }
        }
    }

    // вывод на экран
    void Print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
    }
};