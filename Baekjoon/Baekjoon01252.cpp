// Baekjoon01252.cpp
// https://www.acmicpc.net/problem/1252
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    string a, b;
    cin >> a >> b;

    int n = a.size(), m = b.size();

    int aNum[80], bNum[80];
    for (int i = 0; i < n; i++)
        aNum[i] = a[n - 1 - i] - '0';
    for (int i = 0; i < m; i++)
        bNum[i] = b[m - 1 - i] - '0';

    int result[100] = { 0, }, carry = 0;
    for (int i = 0; i < min(n, m); i++) {
        result[i] = aNum[i] + bNum[i] + carry;
        carry = result[i] / 2;
        result[i] %= 2;
    }

    if (n == m)
        result[n] = carry;
    else if (n < m) {
        for (int i = n; i < m; i++) {
            result[i] = bNum[i] + carry;
            carry = result[i] / 2;
            result[i] %= 2;
        }
        result[m] = carry;
    } else {
        for (int i = m; i < n; i++) {
            result[i] = aNum[i] + carry;
            carry = result[i] / 2;
            result[i] %= 2;
        }
        result[n] = carry;
    }

    int start = 99;
    while (start >= 0 && result[start] == 0)
        start--;
    
    if (start < 0)
        cout << "0";
    else {
        for (int i = start; i >= 0; i--)
            cout << result[i];   
    }
    cout << endl;

    return 0;
}