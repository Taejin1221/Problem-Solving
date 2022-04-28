#include <iostream>

using namespace std;

int main(){
	int x, k;
	cin >> x >> k;
	
	x *= 1000, k *= 1000;
	
	int ans = 0;
	int snowmen[3];
	snowmen[0] = k + k * 2 + k * 4;
	snowmen[1] = k / 2 + k + k * 2;
	snowmen[2] = k / 4 + k / 2 + k;
	
	if (snowmen[0] <= x)
		ans = snowmen[0];
	else if (snowmen[1] <= x)
		ans = snowmen[1];
	else if (snowmen[2] <= x)
		ans = snowmen[2];
	
	cout << ans << '\n';
    
    return 0;

}
