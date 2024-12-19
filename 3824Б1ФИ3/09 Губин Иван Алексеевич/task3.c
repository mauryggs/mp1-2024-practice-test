// Задача 3. Дана строка s и натуральное число N.
// Сформировать строку ss длины N следующим образом.
// Если длина строки s больше или равна N,
//   то включить в ss N последних символов строки s.
// Если длина строки s меньше N,
//   то включить в ss все символы строки s, добавив перед ними символы '*'.
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

char* task3(char* s, unsigned N) {
    static char ss[MAX_LENGTH];
    int len = strlen(s); 
    int j = 0; 

    if (len >= N) {
        for (int i = len - N; i < len; i++) {
            ss[j++] = s[i];
        }
        ss[j] = '\0';
    }
    else {
        for (int i = 0; i < len; i++) {
            ss[j++] = '*'; 
            ss[j++] = s[i]; 
        }

        while (j < N) {
            ss[j++] = '*';
        }
        ss[j] = '\0';
    }

    return ss;
}

int main() {
    char s[] = "abcd";
    unsigned N = 5;
    char* result = task3(s, N);
    printf("Result: %s\n", result);
    return 0;
}
