// Baekjoon06763.cpp
// https://www.acmicpc.net/problem/6763
#include <iostream>

using namespace std;

int main(){
	int limit, curr;
	cin >> limit >> curr;
	
	int over = limit - curr;
	if (over >= 0)
		cout << "Congratulations, you are within the speed limit!";
	else {
		over *= -1;
	
		int fee;
		if (over <= 20)
			fee = 100;
		else if (over <= 30)
			fee = 270;
		else
			fee = 500;
	
		cout << "You are speeding and your fine is $" << fee << ".";
	}
	cout << '\n';
    
    return 0;

}
