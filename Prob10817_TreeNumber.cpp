// Prob10817_TreeNumber.cpp
#include <iostream>

using namespace std;

int main(void) {
    int a, b, c;
    int second;
    
    cin >> a >> b >> c;
    
    if (a > b) {
        if (a > c) {
            if (b > c)
                second = b;
            else
                second = c;
        } else
            second = a;         
    } else {
        if (b > c) {
            if (a > c)
                second = a;
            else
                second = c;
        } else {
            second = b;
        }
    }
    
    cout << second << endl;
    
    return 0;
}
