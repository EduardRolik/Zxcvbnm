#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char date[11];
    int year, month, day;

    printf("Введите дату в формате гггг.мм.дд или гггг.мм: ");
    scanf("%s", date);

    char *  token = strtok(date, ".");
    year = atoi(token);
    token = strtok(NULL, ".");
    month = atoi(token);
    token = strtok(NULL, ".");
    if (token != NULL) {
        day = atoi(token);

        struct tm timeinfo = {0};
        timeinfo.tm_year = year - 1900;
        timeinfo.tm_mon = month - 1;
        timeinfo.tm_mday = day;
        mktime(&timeinfo);

        char weekday[25];
        switch (timeinfo.tm_wday) {
            case 0:
                strcpy(weekday, "Воскресенье");
                break;
            case 1:
                strcpy(weekday, "Понедельник");
                break;
            case 2:
                strcpy(weekday, "Вторник");
                break;
            case 3:
                strcpy(weekday, "Среда");
                break;
            case 4:
                strcpy(weekday, "Четверг");
                break;
            case 5:
                strcpy(weekday, "Пятница");
                break;
            case 6:
                strcpy(weekday, "Суббота");
                break;
        }

        printf("День недели для указанной даты: %s\n", weekday);
    } else {
        struct tm timeinfo = {0};
        timeinfo.tm_year = year - 1900;
        timeinfo.tm_mon = month - 1;
        timeinfo.tm_mday = 1;
        mktime(&timeinfo);

        char monthname[20];
        switch (timeinfo.tm_mon) {
            case 0:
                strcpy(monthname, "Январь");
                break;
            case 1:
                strcpy(monthname, "Февраль");
                break;
            case 2:
                strcpy(monthname, "Март");
                break;
            case 3:
                strcpy(monthname, "Апрель");
                break;
            case 4:
                strcpy(monthname, "Май");
                break;
            case 5:
                strcpy(monthname, "Июнь");
                break;
            case 6:
                strcpy(monthname, "Июль");
                break;
            case 7:
                strcpy(monthname, "Август");
                break;
            case 8:
                strcpy(monthname, "Сентябрь");
                break;
            case 9:
                strcpy(monthname, "Октябрь");
                break;
            case 10:
                strcpy(monthname, "Ноябрь");
                break;
            case 11:
                strcpy(monthname, "Декабрь");
                break;
        }

        printf("Месяц: %s\n", monthname);
    }

    return 0;
}
