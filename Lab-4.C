#include <stdio.h> 
int main() { 
    double matrix1[3][3]; 
    int matrix2[2][2]; 
    double sum_main = 0, sum_secondary = 0; 
    int i, j; 
   
    printf("Введите элементы матрицы 3x3:\n"); 
    for(i = 0; i < 3; i++) { 
        for(j = 0; j < 3; j++) { 
            scanf("%lf", &matrix1[i][j]); 
            if(i == j) 
                sum_main += matrix1[i][j]; 
            if(i + j == 2) 
                sum_secondary += matrix1[i][j]; 
        } 
    } 
    printf("Сумма элементов на глав. диаг.: %.2lf\n", sum_main); 
    printf("Сумма элементов на побоч. диаг.: %.2lf\n", sum_secondary); 
    printf("Введите элементы матрицы 2x2:\n"); 
    for(i = 0; i < 2; i++) { 
        for(j = 0; j < 2; j++) { 
            scanf("%d", &matrix2[i][j]); 
        } 
    } 
    printf("Квадрат матрицы:\n"); 
    for(i = 0; i < 2; i++) { 
        for(j = 0; j < 2; j++) { 
            printf("%d ", matrix2[i][j] * matrix2[i][j]); 
        } 
        printf("\n"); 
    } 
 
    return 0; 
}
qweqweqweqweqweqweqwe
