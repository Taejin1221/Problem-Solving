// Prob9498_Grade.c
#include <stdio.h>

int main(void) {
    int num1;
     
    scanf("%d", &num1);
    
    if (num1 >= 90) putchar('A');
    else if (num1 >= 80) putchar('B');
    else if (num1 >= 70) putchar('C');
    else if (num1 >= 60) putchar('D');
    else putchar('F');
    
    return 0;
}
