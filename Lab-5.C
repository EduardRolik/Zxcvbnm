#include <stdio.h> 
#include <stdlib.h> 
#include "matrix_operations.h" 
 
int main() { 
    int n; 
    printf("Введите размерность матрицы: "); 
    scanf("%d", &n); 
 
    double** matrix1 = createMatrix(n); 
    double** matrix2 = createMatrix(n); 
    double** resultMatrix; 
 
    printf("Введите элементы первой матрицы:\n"); 
    fillMatrix(matrix1, n); 
 
    printf("Введите элементы второй матрицы:\n"); 
    fillMatrix(matrix2, n); 
 
    char operation; 
    printf("Введите знак операции (+, -, *): "); 
    scanf(" %c", &operation); 
 
    switch (operation) { 
        case '+': 
            resultMatrix = addMatrix(matrix1, matrix2, n); 
            break; 
        case '-': 
            resultMatrix = subtractMatrix(matrix1, matrix2, n); 
            break; 
        case '*': 
            resultMatrix = multiplyMatrix(matrix1, matrix2, n); 
            break; 
        default: 
            printf("Неверный знак операции!\n"); 
            return 1; 
    } 
 
    printf("Результат операции:\n"); 
    printMatrix(resultMatrix, n); 
 
    freeMatrix(matrix1, n); 
    freeMatrix(matrix2, n); 
    freeMatrix(resultMatrix, n); 
 
    return 0; 
}
wqewqeqweqw
