#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Определение структуры Student
struct Student {
    char surname[50];
    char group[10];
    int numberInGroup;
    int scholarship;
};

// Функция для ввода данных о студентах
void insertStudentData(struct Student *students[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Введите данные для студента %d:\n", i + 1);

        printf("Фамилия: ");
        scanf("%s", students[i]->surname);

        printf("Группа: ");
        scanf("%s", students[i]->group);

        printf("Номер в группе: ");
        scanf("%d", &students[i]->numberInGroup);

        printf("Стипендия: ");
        scanf("%d", &students[i]->scholarship);
    }
}

// Функция для вывода данных о студентах
void printStudentData(struct Student *students[], int count) {
    printf("\nДанные студентов:\n");
    for (int i = 0; i < count; i++) {
        printf("Студент %d: Фамилия: %s, Группа: %s, Номер в группе: %d, Стипендия: %d\n",
               i + 1, students[i]->surname, students[i]->group, students[i]->numberInGroup, students[i]->scholarship);
    }
}

// Функция сравнения для qsort
int compare(const void *a, const void *b) {
    struct Student *studentA = *(struct Student **)a;
    struct Student *studentB = *(struct Student **)b;
    return studentA->numberInGroup - studentB->numberInGroup;
}

int main(void) {
    int studentCount;

    printf("Введите количество студентов: ");
    scanf("%d", &studentCount);

    if (studentCount <= 0) {
        printf("Некорректное количество студентов.\n");
        return 1;
    }

    // Используем массив указателей на структуры и динамическое выделение памяти
    struct Student **students = malloc(studentCount * sizeof(struct Student *));
    for (int i = 0; i < studentCount; i++) {
        students[i] = malloc(sizeof(struct Student));
    }

    // Вводим данные о студентах
    insertStudentData(students, studentCount);

    // Сортируем массив указателей на структуры по номеру в группе
    qsort(students, studentCount, sizeof(struct Student *), compare);

    // Выводим данные о студентах
    printStudentData(students, studentCount);

    // Освобождаем выделенную память
    for (int i = 0; i < studentCount; i++) {
        free(students[i]);
    }
    free(students);

    return 0;
}



