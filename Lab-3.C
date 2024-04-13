#include <stdio.h> 
#include <math.h> 
 
double calculatePerimeter(double a, double b, double c) { 
    return a + b + c; 
} 
 
double calculatePloshad(double a, double b, double c) { 
    double semiPerimeter = calculatePerimeter(a, b, c) / 2; 
    return sqrt(semiPerimeter * (semiPerimeter - a) * (semiPerimeter - b) * (semiPerimeter - c)); 
} 
 
int main() { 
    double a, b, c; 
 
    printf("Введите длины сторон треугольника: "); 
    scanf("%lf %lf %lf", &a, &b, &c); 
 
    if (a + b > c && a + c > b && b + c > a) { 
        double perimeter = calculatePerimeter(a, b, c); 
        double ploshad = calculatePloshad(a, b, c); 
 
        printf("Периметр треугольника: %lf\n", perimeter); 
        printf("Площадь треугольника: %lf\n", ploshad); 
    } else { 
        printf("Треугольник с такими сторонами не существует!\n"); 
    } 
 
    return 0; 
}
qwertqdsdafwq
