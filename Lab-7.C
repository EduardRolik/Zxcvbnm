#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50]; 
    char surname[50]; 
    int year; 
} humen;

int main() {
    const int ARRAY_SIZE = 8; 
    humen people[ARRAY_SIZE]; 
    humen sortedPeople[ARRAY_SIZE]; 

    FILE  * file = fopen("people.txt", "r");
    if (file == NULL) {
        perror("Ошибка при открытии файла");
        return EXIT_FAILURE;
    }

    
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        fscanf(file, "%49s %49s %d", people[i].name, people[i].surname, &people[i].year);
    }

    
    fclose(file);

    
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        sortedPeople[i] = people[i];
    }

    
    for (int i = 0; i < ARRAY_SIZE - 1; ++i) {
        for (int j = 0; j < ARRAY_SIZE - i - 1; ++j) {
            if (sortedPeople[j].year > sortedPeople[j + 1].year) {
                humen temp = sortedPeople[j];
                sortedPeople[j] = sortedPeople[j + 1];
                sortedPeople[j + 1] = temp;
            }
        }
    }

    
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        printf("%s %s %d\n", sortedPeople[i].name, sortedPeople[i].surname, sortedPeople[i].year);
    }

    return EXIT_SUCCESS;
}
