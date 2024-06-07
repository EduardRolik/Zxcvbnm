#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *input_file, *output_file;
    int N, M;
    int i, j;
    clock_t start, end;
    double cpu_time_used;
    
    printf("Введите размер массива o_o: ");
    scanf("%d", &N);

    input_file = fopen("input.txt", "w");
    if (input_file == NULL) {
        perror("Ошибка открытия файла input.txt для записи :( ");
        return 1;
    }
    srand(time(NULL));
    for (i = 0; i < N; i++) {
        fprintf(input_file, "%d ", rand() % 100);
    }
    fclose(input_file);

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        perror("Ошибка открытия файла input.txt для чтения :( ");
        return 1;
    }
    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        perror("Ошибка открытия файла output.txt для записи :( ");
        fclose(input_file);
        return 1;
    }
    
    while (fscanf(input_file, "%d", &j) != EOF) {
        if (j % 35 == 0) {
            fprintf(output_file, "ПЯТЬСЕМЬ ");
        } else if (j % 5 == 0) {
            fprintf(output_file, "ПЯТЬ ");
        } else if (j % 7 == 0) {
            fprintf(output_file, "СЕМЬ ");
        } else {
            fprintf(output_file, "%d ", j);
        }
    }
    
    fclose(input_file);
    fclose(output_file);

    M = N / 2;
    int matrix[M][2];
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        perror("Ошибка открытия файла input.txt для чтения :( ");
        return 1;
    }
    
    for (i = 0; i < M; i++) {
        for (j = 0; j < 2; j++) {
            fscanf(input_file, "%d", &matrix[i][j]);
        }
    }
    fclose(input_file);

    int sum_rows = 0, sum_cols = 0;
    for (i = 0; i < M; i++) {
        int row_sum = 0;
        for (j = 0; j < 2; j++) {
            row_sum += matrix[i][j];
        }
        sum_rows += row_sum;
    }

    for (j = 0; j < 2; j++) {
        for (i = 0; i < M; i++) {
            sum_cols += matrix[i][j];
        }
    }

    printf("Матрица +_+:\n");
    for (i = 0; i < M; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("Сумма строк O_o: %d\n", sum_rows);
    printf("Сумма столбцов o_O: %d\n", sum_cols);

    start = clock();
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Время затраченное программой x_x: %f секунд <3\n", cpu_time_used);

    return 0;
}
