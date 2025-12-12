#include <stdio.h>

// Функция для обмена двух элементов
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Функция для пузырьковой сортировки
void bubbleSort(int arr[], int n) {
    int i, j;
    // Проходим по всем элементам массива
    for (i = 0; i < n - 1; i++) {
        // Последние i элементов уже на своих местах
        for (j = 0; j < n - i - 1; j++) {
            // Сравниваем соседние элементы
            if (arr[j] > arr[j + 1]) {
                // Меняем местами, если текущий элемент больше следующего
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Функция для печати массива
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Главная функция
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Исходный массив: \n");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Отсортированный массив: \n");
    printArray(arr, n);

    return 0;
}