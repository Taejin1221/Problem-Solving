// Baekjoon15596_NSum.cpp
long long sum(std::vector<int> &a) {
	int sum = 0;
	for (int i = 0; i < a.size(); i++)
		sum += a[i];
	return sum;
}