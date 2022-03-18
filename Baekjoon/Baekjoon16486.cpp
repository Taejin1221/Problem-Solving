// Baekjoon16486.cpp
// https://www.acmicpc.net/problem/16486
#include <cstdio>

using namespace std;

const double PI = 3.141592;

int main(){
    double length, radius;
    scanf("%lf", &length);
    scanf("%lf", &radius);

    printf("%.6f\n", 2 * length + 2 * PI * radius);
    
    return 0;

}
