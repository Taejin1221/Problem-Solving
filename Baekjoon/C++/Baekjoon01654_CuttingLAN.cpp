// Baekjoon01654_CuttingLAN.cpp
// https://www.acmicpc.net/problem/1654
#include <cstdio>

int haveLAN, needLAN;
int LANs[10000];

int CutLAN( int cm ) {
	int num = 0;
	for ( int lan : LANs )
		num += lan / cm;

	return num;
}

int main(void) {
	scanf("%d %d", &haveLAN, &needLAN );

	int maxLAN = 0;
	for ( int i = 0; i < haveLAN; i++ ) {
		scanf("%d", &LANs[i]);
		maxLAN = ( maxLAN < LANs[i] ) ? LANs[i] : maxLAN;
	}

	long long mid;
	long long left = 1, right = ((long long)maxLAN) + 1;
	while ( left + 1 < right ) {
		mid = ( left + right ) / 2;
		if ( CutLAN(mid) >= needLAN )
			left = mid;
		else
			right = mid;
	}

	printf("%lld\n", left);

	return 0;
}