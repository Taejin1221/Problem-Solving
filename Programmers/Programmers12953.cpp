// Programmers12953.cpp
// https://school.programmers.co.kr/learn/courses/30/lessons/12953?language=cpp
#include <vector>

using namespace std;

int GCD(int a, int b) {
    return (a % b) ? GCD(b, a % b) : b;
}

long long solution(vector<int> arr) {
    int answer = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        int gcd = answer > arr[i] ? GCD(answer, arr[i]) : GCD(arr[i], answer);
        answer = answer * arr[i] / gcd;
    }

    return answer;
}
