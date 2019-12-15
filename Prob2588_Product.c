// Prob2588_Product.c
#include <stdio.h>

int main(void) {
    int num1, num2;
    
    scanf("%d %d", &num1, &num2);
    
    printf("%d\n", num1 * (num2 % 10));
    printf("%d\n", num1 * (num2 / 10 % 10));
    printf("%d\n", num1 * (num2 / 100));
    printf("%d\n", num1 * num2);
    
    return 0;
}