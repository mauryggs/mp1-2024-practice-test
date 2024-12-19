// Задача 1. Дан непустой массив A, содержащий n целых чисел.
// Найти номер его последнего минимального элемента.
#include <stdio.h>
#include <limits.h> // Для INT_MAX

int find_last_min_index(int arr[], int n) {

    int min_val = INT_MAX;
    int min_index = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] <= min_val) {
            min_val = arr[i];
            min_index = i;
        }
    }

    return min_index;
}
