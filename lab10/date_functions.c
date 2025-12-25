#include <stdio.h>
#include <stdlib.h>
#include "date_functions.h"

// Функция для создания структуры в динамической памяти
struct Date* create_date(int d, int m, int y) {
    struct Date* date = (struct Date*)malloc(sizeof(struct Date));
    if (date != NULL) {
        date->day = d;
        date->month = m;
        date->year = y;
    }
    return date;
}

// Функция для инициализации существующей структуры через указатель
void init_date(struct Date* date, int d, int m, int y) {
    if (date != NULL) {
        date->day = d;
        date->month = m;
        date->year = y;
    }
}

// Функция для анализа даты (принимает структуру по значению)
void analyze_date(struct Date date) {
    // Определение декады
    int decade = (date.day - 1) / 10 + 1;
    
    // Определение сезона
    char* season;
    if (date.month == 12 || date.month <= 2) season = "Зима";
    else if (date.month >= 3 && date.month <= 5) season = "Весна";
    else if (date.month >= 6 && date.month <= 8) season = "Лето";
    else season = "Осень";
    
    // Определение века
    int century = (date.year - 1) / 100 + 1;
    
    printf("Декада: %d-я, Сезон: %s, Век: %d-й\n", decade, season, century);
}

// Функция для анализа даты (принимает указатель на структуру)
void analyze_date_ptr(struct Date* date) {
    if (date == NULL) {
        printf("Ошибка: указатель на дату равен NULL!\n");
        return;
    }
    
    // Определение декады
    int decade = (date->day - 1) / 10 + 1;
    
    // Определение сезона
    char* season;
    if (date->month == 12 || date->month <= 2) season = "Зима";
    else if (date->month >= 3 && date->month <= 5) season = "Весна";
    else if (date->month >= 6 && date->month <= 8) season = "Лето";
    else season = "Осень";
    
    // Определение века
    int century = (date->year - 1) / 100 + 1;
    
    printf("Декада: %d-я, Сезон: %s, Век: %d-й\n", decade, season, century);
}
