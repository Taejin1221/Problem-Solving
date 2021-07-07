// Prob1330_CompareTwoNumbers.c
#include <stdio.h>

int main(void) {
    int a, b;
    
    scanf("%d %d", &a, &b);
    
    if (a > b) puts(">");
    else if (a < b) puts("<");
    else puts("==");
    
    return 0;
}
