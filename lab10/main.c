#include <stdio.h>
#include <stdlib.h>
#include "date_functions.h"

int main() {
    int N;
    
    printf("Введите количество человек: ");
    scanf("%d", &N);
    
    if (N <= 0) {
        printf("Ошибка: количество должно быть положительным!\n");
        return 1;
    }
    
    // Динамическое выделение памяти для массива указателей на структуры
    struct Date** dates = (struct Date**)malloc(N * sizeof(struct Date*));
    if (dates == NULL) {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }
    
    // Ввод дат рождения
    for (int i = 0; i < N; i++) {
        int d, m, y;
        printf("Введите дату рождения %d (день месяц год): ", i + 1);
        scanf("%d %d %d", &d, &m, &y);
        
        // Динамическое создание структуры и получение указателя на нее
        dates[i] = create_date(d, m, y);
        if (dates[i] == NULL) {
            printf("Ошибка создания даты!\n");
            
            // Освобождение уже выделенной памяти перед выходом
            for (int j = 0; j < i; j++) {
                free(dates[j]);
            }
            free(dates);
            return 1;
        }
    }
    
    // Вывод информации
    printf("\nРезультаты:\n");
    for (int i = 0; i < N; i++) {
        printf("Человек %d: ", i + 1);
        // Использование функции для анализа даты (передача указателя)
        analyze_date_ptr(dates[i]);
    }
    
    // Освобождение памяти
    for (int i = 0; i < N; i++) {
        free(dates[i]);
    }
    free(dates);
    
    return 0;
}