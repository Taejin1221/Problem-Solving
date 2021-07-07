// Baekjoon02522_PrintStar12.cpp
// https://www.acmicpc.net/problem/2522
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);

    int n;
    cin >> n;

    for ( int i = 1; i <= n; i++ ) {
        for ( int j = 0; j < ( n - i ); j++ )
            cout << ' ';
        for ( int j = 0; j < i; j++ )
            cout << '*';
        cout << '\n';
    }

    for ( int i = 1; i < n; i++ ) {
        for ( int j = 0; j < i; j++ )
            cout << ' ';
        for ( int j = 0; j < ( n - i ); j++ )
            cout << '*';
        cout << '\n';
    }

    return 0;
}
