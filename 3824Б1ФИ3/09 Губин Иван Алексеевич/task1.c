// Задача 1. Дан непустой массив A, содержащий n целых чисел.
// Найти номер его последнего минимального элемента.
#include <stdio.h>
#include <limits.h>
#include <stddef.h> 

int find_last_min_index(int A[], size_t n) {

    int min_val = INT_MAX;
    int min_index = -1;

    for (size_t i = 0; i < n; i++) {
        if (A[i] <= min_val) {
            min_val = A[i];
            min_index = (int)i; // Приведение типа к int, так как возвращаем int
        }
    }

    return min_index;
}
