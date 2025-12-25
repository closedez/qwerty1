#ifndef DATE_FUNCTIONS_H
#define DATE_FUNCTIONS_H

// Структура для даты
struct Date {
    int day;
    int month;
    int year;
};

// Прототипы функций
struct Date* create_date(int d, int m, int y);          // Создание даты в динамической памяти
void analyze_date(struct Date date);                    // Анализ по значению
void analyze_date_ptr(struct Date* date);               // Анализ по указателю
void init_date(struct Date* date, int d, int m, int y); // Инициализация существующей структуры
// 32432432432
#endif