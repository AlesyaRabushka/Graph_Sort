#include "Sort.h"
#include <iostream>
#include <vector>

using namespace std;


GnomeSort::GnomeSort() {
    size = 0;
    arr = new int();
}










/*
gnomeSort(a[0..size - 1])
    i = 1;
    j = 2;
    while i < size
        if a[i - 1] <= a[i] //для сортировки по убыванию поменяйте знак сравнения на >=
            i = j;
            j = j + 1;
        else
            swap a[i - 1] and a[i]
            i = i - 1;
            if i == 0
                i = j;
                j = j + 1;
 */