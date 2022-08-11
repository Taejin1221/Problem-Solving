// Baekjoon01598.cpp
// https://www.acmicpc.net/problem/1598
#include <iostream>

using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    
    pair<int, int> a, b;
    if (n % 4 == 0)
    	a = { n / 4 - 1, 4 };
    else
    	a = { n / 4, n % 4 };

    if (m % 4 == 0)
    	b = { m / 4 - 1, 4 };
    else
    	b = { m / 4, m % 4 };

    cout << abs(b.first - a.first) + abs(b.second - a.second) << endl;
    
    return 0;
}