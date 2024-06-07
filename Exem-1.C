#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
 
void generateMatrix(int** matrix, int rows, int cols) { 
    for (int i = 0; i < rows; i++) { 
        for (int j = 0; j < cols; j++) { 
            matrix[i][j] = rand() % 10;
        } 
    } 
} 
 
void addMatrices(int** matrix1, int** matrix2, int** result, int rows, int cols) { 
    for (int i = 0; i < rows; i++) { 
        for (int j = 0; j < cols; j++) { 
            result[i][j] = matrix1[i][j] + matrix2[i][j]; 
        } 
    } 
} 
 
void multiplyMatrices(int** matrix1, int** matrix2, int** result, int rows1, int cols1, int cols2) { 
    for (int i = 0; i < rows1; i++) { 
        for (int j = 0; j < cols2; j++) { 
            result[i][j] = 0; 
            for (int k = 0; k < cols1; k++) { 
                result[i][j] += matrix1[i][k] * matrix2[k][j]; 
            } 
        } 
    } 
} 
 
int main() { 
    int rows, cols; 
    printf("Введите количество строк :): "); 
    scanf("%d", &rows); 
    printf("Введите количество столбцов :): "); 
    scanf("%d", &cols); 
 
    int** matrix1 = (int**)malloc(rows * sizeof(int*)); 
    int** matrix2 = (int**)malloc(rows * sizeof(int*)); 
    int** result = (int**)malloc(rows * sizeof(int*)); 
    for (int i = 0; i < rows; i++) { 
        matrix1[i] = (int*)malloc(cols * sizeof(int)); 
        matrix2[i] = (int*)malloc(cols * sizeof(int)); 
        result[i] = (int*)malloc(cols * sizeof(int)); 
    } 
 
    srand(time(NULL)); 
    generateMatrix(matrix1, rows, cols); 
    generateMatrix(matrix2, rows, cols); 
 
    FILE* file = fopen("input.txt", "w"); 
    if (file != NULL) { 
        fprintf(file, "Первая матрица o_O:\n"); 
        for (int i = 0; i < rows; i++) { 
            for (int j = 0; j < cols; j++) { 
                fprintf(file, "%d ", matrix1[i][j]); 
            } 
            fprintf(file, "\n"); 
        } 
        fprintf(file, "Вторая матрица O_o:\n"); 
        for (int i = 0; i < rows; i++) { 
            for (int j = 0; j < cols; j++) { 
                fprintf(file, "%d ", matrix2[i][j]); 
            } 
            fprintf(file, "\n"); 
        } 
        fclose(file); 
    } 
 
    addMatrices(matrix1, matrix2, result, rows, cols); 
 
    file = fopen("output.txt", "w"); 
    if (file != NULL) { 
        fprintf(file, "Результат сложения матриц +_+:\n"); 
        for (int i = 0; i < rows; i++) { 
            for (int j = 0; j < cols; j++) { 
                fprintf(file, "%d ", result[i][j]); 
            } 
            fprintf(file, "\n"); 
        } 
        fclose(file); 
    } 
 
    multiplyMatrices(matrix1, matrix2, result, rows, cols, cols); 
 
    file = fopen("output.txt", "a"); 
    if (file != NULL) { 
        fprintf(file, "Результат умножения матриц x_x :\n"); 
        for (int i = 0; i < rows; i++) { 
            for (int j = 0; j < cols; j++) { 
                fprintf(file, "%d ", result[i][j]); 
            } 
            fprintf(file, "\n"); 
        } 
        fclose(file); 
    } 
 
    for (int i = 0; i < rows; i++) { 
        free(matrix1[i]); 
        free(matrix2[i]); 
        free(result[i]); 
    } 
    free(matrix1); 
    free(matrix2); 
    free(result); 
 
    clock_t start = clock(); 
    clock_t end = clock(); 
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC; 
    printf("Время работы программы O_O: %f секунд <3 \n", time_spent); 
 
    return 0; 
}
