// Baekjoon02712.cpp
// https://www.acmicpc.net/problem/2712
#include <iostream>
#include <cstdio>

#include <string>

using namespace std;

int main(){
	int t;
	cin >> t;
	
	while (t--) {
		double num;
		string unit;
		
		cin >> num >> unit;
		
		if (unit == "kg")
			printf("%.4f lb\n", num * 2.2046);
		else if (unit == "lb")
			printf("%.4f kg\n", num * 0.4536);
		else if (unit == "l")
			printf("%.4f g\n", num * 0.2642);
		else
			printf ("%.4f l\n", num * 3.7854);
	}

	return 0;
}
