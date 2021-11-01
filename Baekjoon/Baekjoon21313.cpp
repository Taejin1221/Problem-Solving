// Baekjoon21313.cpp
// https://www.acmicpc.net/problem/21313
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    
    for (int i = 0; i < n / 2; i++)
        cout << 1 << ' ' << 2 << ' ';
  
    if (n % 2)
        cout << 3;
    
    return 0;
}
