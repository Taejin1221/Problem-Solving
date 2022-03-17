// Baekjoon16431.cpp
// https://www.acmicpc.net/problem/16431
#include <iostream>

using namespace std;

using pii = pair<int, int>;

int main() {
    pii bessie, daisy, john;
    cin >> bessie.first >> bessie.second;
    cin >> daisy.first >> daisy.second;
    cin >> john.first >> john.second;

    int bessieDiff = max(abs(john.first - bessie.first), abs(john.second - bessie.second));
    int daisyDiff = abs(john.first - daisy.first) + abs(john.second - daisy.second);

    if (bessieDiff < daisyDiff)
        cout << "bessie";
    else if (bessieDiff > daisyDiff)
        cout << "daisy";
    else
        cout << "tie";
    cout << endl;

    return 0;
}
