/** Задание к зачету. Гусятинер Л.Б,, КМПО
Вариант 30. Москва, КМПО РАНХиГС, 2022/2024
В базе данных лесного колледжа содержатся сведения об успеваемости студентов.
Структура входного файла in.txt (Студент Группа Дисциплина Оценки)
Тигра Г1 Физика 3.5
Винни_Пух Г2 Пчеловодство 5.0
Винни_Пух Г2 Русский_язык 3.0
Кролик Г1 Русский_язык 4.75
Тигра Г1 Химия 3.67

…
Сформировать список студентов с любимыми дисциплинами, исходя из среднего балла (гарантируется, что для
каждого студента только одна любимая дисциплина). Список упорядочить по названию группы и по фамилии студента
Структура выходного файла out.txt
Г1 Кролик Русский_язык
Г1 Тигра Химия
Г2 Винни_Пух Пчеловодство
*/
/** Решение. Гусятинер Л.Б., уровень A */
/** Доделал решение. Зайцев Г.В, уровень ? */
/** Этап 1. Считывание. Проверка.
Начало решения 16.03.2024, 22:58
Окончание решения 16.03.2024, 2:53
Время 2:53 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define COLLEDGE_SIZE 1000

typedef struct {
    char gr[20];
    char st[20];
    char disc[20];
    double mark;
} Record;

typedef struct {
    char gr[20];
    char st[20];
    char disc[20];
    double mark;
} Record2;

int main(void) {
    char *locale = setlocale(LC_ALL, "");
    Record v[COLLEDGE_SIZE];
    Record2 v2[COLLEDGE_SIZE] = {0}; // Инициализация массива v2 нулями
    FILE *in = fopen("in.txt", "r");
    int n = 0;
    Record rec;
    char smark[20];
    while (fscanf(in, "%s %s %s %s", rec.st, rec.gr, rec.disc, smark) == 4) {
        rec.mark = atof(smark);
        v[n] = rec;
        n++;
    }
    fclose(in);

    // Заполнение v2
    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < n; j++) {
            if (v[i].mark > v2[j].mark) {
                strcpy(v2[j].gr, v[i].gr);
                strcpy(v2[j].st, v[i].st);
                strcpy(v2[j].disc, v[i].disc);
                v2[j].mark = v[i].mark;
                break;
            }
            if (v2[j].st[0] == '\0') { // Если студента еще нет в v2
                strcpy(v2[j].gr, v[i].gr);
                strcpy(v2[j].st, v[i].st);
                strcpy(v2[j].disc, v[i].disc);
                v2[j].mark = v[i].mark;
                break;
            }
        }
    }

    // Вывод v2
    FILE *out = fopen("out.txt", "w");
    for (int i = 0; i < n; i++) {

        fprintf(out, "%s %s %s\n", v2[i].gr, v2[i].st, v2[i].disc);
    }
    fclose(out);

    return 0;
}


