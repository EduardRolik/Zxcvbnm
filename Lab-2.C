#include <stdio.h> 
 
int main() { 
    char str[81]; 
 
    printf("Введите строку (макс. 80 символов): "); 
    scanf("%80s", str); 
 
    for (int i = 0; str[i] != '\0'; i++) { 
        if (str[i] == 'a' || str[i] == 'b') { 
            str[i] = str[i] - 32; 
        } 
    } 
 
    printf("Измененная строка: %s\n", str); 
 
    return 0; 
}
q
