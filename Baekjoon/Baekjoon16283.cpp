// Baekjoon16283.cpp
// https://www.acmicpc.net/problem/16283
#include <iostream>

using namespace std;

int main(void) {
    int a, b, n, w;
    cin >> a >> b >> n >> w;

    int ans = 0;
    pair<int, int> sg;
    int sheep = 1, goat = n - 1;
    for (int i = 1; i <= n - 1; i++) {
        if (a * sheep + goat * b == w) {
            ans++;
            sg = make_pair(sheep, goat);
        }

        sheep++, goat--;
    }

    if (ans != 1)
        cout << -1;
    else
        cout << sg.first << ' ' << sg.second;
    cout << '\n';

    return 0;
}