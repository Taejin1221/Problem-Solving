// Baekjoon20175.cpp
// https://www.acmicpc.net/problem/20175
#include <cstdio>
#include <climits>

using namespace std;

typedef long long ll;
typedef long double ld;

ld ABS(ld a) {
	return (a < 0.0) ? -a : a;
}

ll min(ll a, ll b) {
	return (a < b) ? a : b;
}

ll max(ll a, ll b) {
	return (a > b) ? a : b;
}

ld min(ld a, ld b) {
	return (a < b) ? a : b;
}

ld max(ld a, ld b) {
	return (a > b) ? a : b;
}

int main(void) {
	ll n, d;
	scanf("%lld %lld", &n, &d);

	ll arr[1'000'000];
	ll minVal = LLONG_MAX, maxVal = LLONG_MIN;
	for (ll i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);

		ll val = arr[i] - i * d;
		minVal = min(minVal, val);
		maxVal = max(maxVal, val);
	}

	ld ans1 = 0.0, s_1 = (ld)(minVal + maxVal) / 2.0;
	for (ll i = 0; i < n; i++)
		ans1 = max(ans1, ABS(s_1 + i * d - arr[i]));

	minVal = LLONG_MAX, maxVal = LLONG_MIN;
	for (ll i = 0; i < n; i++) {
		ll val = arr[n - i - 1] - i * d;
		minVal = min(minVal, val);
		maxVal = max(maxVal, val);
	}

	ld ans2 = 0.0;
	s_1 = (ld)(minVal + maxVal) / 2.0;
	for (ll i = 0; i < n; i++)
		ans2 = max(ans2, ABS(s_1 + i * d - arr[n - i - 1]));

	printf("%.1Lf\n", min(ans1, ans2));

	return 0;
}	