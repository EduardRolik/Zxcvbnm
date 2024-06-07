#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50]; 
    char surname[50]; 
    int year; 
} humen;

int main() {
    humen  * people = NULL;
    humen  * sortedPeople = NULL;
    int size = 0;

    FILE  * file = fopen("people.txt", "r");
    if (file == NULL) {
        perror("Ошибка при открытии файла :( ");
        return EXIT_FAILURE;
    }

    while (1) {
        humen person;
        if (fscanf(file, "%49s %49s %d", person.name, person.surname, &person.year) != 3) {
            break;
        }
        
        people = (humen  * ) realloc(people, (size + 1)  *  sizeof(humen));
        if (people == NULL) {
            perror("Ошибка при выделении памяти :( ");
            fclose(file);
            return EXIT_FAILURE;
        }
        
        memcpy(&people[size], &person, sizeof(humen));
        size++;
    }

    fclose(file);

    sortedPeople = (humen  * ) malloc(size  *  sizeof(humen));
    if (sortedPeople == NULL) {
        perror("Ошибка при выделении памяти :( ");
        free(people);
        return EXIT_FAILURE;
    }

    for (int i = 0; i < size; ++i) {
        sortedPeople[i] = people[i];
    }

    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (sortedPeople[j].year > sortedPeople[j + 1].year) {
                humen temp = sortedPeople[j];
                sortedPeople[j] = sortedPeople[j + 1];
                sortedPeople[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < size; ++i) {
        printf("%s %s %d\n", sortedPeople[i].name, sortedPeople[i].surname, sortedPeople[i].year);
    }

    free(sortedPeople);
    free(people);

    return EXIT_SUCCESS;
}
