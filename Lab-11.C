#include <stdio.h> 
#include <stdarg.h> 

double sum(int count, ...) 
{ 
    double result = 0; 
    va_list args; 
    va_start(args, count); 
 
    for (int i = 0; i < count; i++) { 
        result += va_arg(args, double); 
    } 
 
    va_end(args); 
    return result; 
} 

double max(int count, ...) 
{ 
    double result = 0; 
    va_list args; 
    va_start(args, count); 
 
    for (int i = 0; i < count; i++) { 
        double value = va_arg(args, double); 
        if (i == 0  value > result) { 
            result = value; 
        } 
    } 
 
    va_end(args); 
    return result; 
} 

double min(int count, ...) 
{ 
    double result = 0; 
    va_list args; 
    va_start(args, count); 
 
    for (int i = 0; i < count; i++) { 
        double value = va_arg(args, double); 
        if (i == 0  value < result) { 
            result = value; 
        } 
    } 
 
    va_end(args); 
    return result; 
} 

double average(int count, ...) 
{ 
    double result = 0; 
    va_list args; 
    va_start(args, count); 
 
    for (int i = 0; i < count; i++) { 
        result += va_arg(args, double); 
    } 
 
    va_end(args); 
    return result / count; 
} 
 
int main() 
{ 
    double sumResult = sum(4, 1.5, 2.5, 3.5, 41.5); 
    double maxResult = max(3, 10.5, 20.7, 5.2); 
    double minResult = min(5, 6.4, 3.2, 8.9, 4.1, 2.7); 
    double averageResult = average(6, 2.5, 4.5, 6.5, 8.5, 10.5, 112.5); 
 
    printf("Сумма: %.2f\n", sumResult); 
    printf("Максимум: %.2f\n", maxResult); 
    printf("Минимум: %.2f\n", minResult); 
    printf("Среднее арифметическое: %.2f\n", averageResult); 
 
    return 0; 
}
