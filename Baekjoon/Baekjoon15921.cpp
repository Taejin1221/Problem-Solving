// Baekjoon15921.cpp
#include <cstdio>

using namespace std;

int main(void) {
	int n;
	scanf("%d", &n);

	if (n == 0)
		printf("divide by zero\n");
	else {
		int sum = 0;
		int records[100], table[101] = { 0, };
		for (int i = 0; i < n; i++) {
			scanf("%d", &records[i]);
			sum += records[i];
			table[records[i]]++;
		}

		double average = (double)sum / n;
		double expectation = 0.0;
		for (int i = 1; i <= 100; i++) {
			expectation += i * ((double)table[i] / n);
		}

		printf("%.2f\n", average / expectation);
	}

	return 0;
}