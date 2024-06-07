#include <stdio.h> 
 
#define MAX(a, b) ((a) > (b) ? (a) : (b)) 
 
int main() { 
  int numbers[100]; 
  int count; 
 
  printf("Введите количество чисел: "); 
  scanf("%d", &count); 
 
  printf("Введите числа через пробел: "); 
  for (int i = 0; i < count; i++) { 
    scanf("%d", &numbers[i]); 
  } 
 
  int max = numbers[0]; 
  for (int i = 1; i < count; i++) { 
    max = MAX(max, numbers[i]); 
  } 
 
  printf("Максимальное число: %d\n", max); 
 
  return 0; 
}
