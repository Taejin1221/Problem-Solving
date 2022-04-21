// Baekjoon20233.cpp
#include <iostream>

using namespace std;

int main(){
	int a, x, b, y, t;
	cin >> a >> x >> b >> y >> t;
	
	int ansFirst = 21 * max(0, t - 30) * x + a, ansSecond = 21 * max(0, t - 45) * y + b;
	
	cout << ansFirst << ' ' << ansSecond << '\n';
    
    return 0;

}
