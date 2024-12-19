// Задача 2. Дан непустой массив A, содержащий n натуральных чисел.
// Найти значение минимального из его локальных максимумов.
// Локальный максимум – элемент, который >= левого и правого соседей.
// При отсутствии локальных максимумов вернуть -1.
#include <stdio.h>
#include <limits.h>
#include <stddef.h>
#include <stdbool.h>

long long task2(unsigned int A[], size_t n) {
    if (n == 0) {
        return -1;
    }

    if (n == 1) {
        return -1;
    }

    long long min_local_max = LLONG_MAX;
    int local_max_found = 0;
    bool is_increasing = true;
    bool is_decreasing = true;



    for (size_t i = 1; i < n; i++) {
        if (A[i] <= A[i - 1]) {
            is_increasing = false;
        }

        if (A[i] >= A[i - 1]) {
            is_decreasing = false;
        }
    }


    for (size_t i = 0; i < n; i++) {
        if (i > 0 && i < n - 1) {
            if (A[i] >= A[i - 1] && A[i] >= A[i + 1]) {
                if ((long long)A[i] < min_local_max) {
                    min_local_max = (long long)A[i];
                }
                local_max_found = 1;
            }
        }
        else if (i == 0 && n > 1 && A[0] >= A[1]) {
            if ((long long)A[i] < min_local_max) {
                min_local_max = (long long)A[i];
            }
            local_max_found = 1;
        }
        else if (i == n - 1 && n > 1 && A[n - 1] >= A[n - 2]) {
            if ((long long)A[i] < min_local_max) {
                min_local_max = (long long)A[i];
            }
            local_max_found = 1;
        }
    }

    if (is_increasing || is_decreasing) {
        return -1;
    }

    if (local_max_found) {
        return min_local_max;
    }
    else {
        return -1;
    }
}
