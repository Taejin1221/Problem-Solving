// Baekjoon10179.cpp
// https://www.acmicpc.net/problem/10179
#include <cstdio>

using namespace std;

int main(void) {
    int t;
    scanf("%d", &t);
    while (t--) {
        double price;
        scanf("%lf", &price);

        printf("$%.2lf\n", price * 0.8);
    }

    return 0;
}