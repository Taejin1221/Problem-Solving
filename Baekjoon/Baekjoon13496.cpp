#include <iostream>

using namespace std;

int main(){
	int t;
	cin >> t;

	for (int j = 1; j <= t; j++) {
		int n, s, d;
		cin >> n >> s >> d;
		
		int totalMile = s * d;

		int ans = 0;
		for (int i = 0; i < n; i++) {
			int d_i, v;
			cin >> d_i >> v;
			
			if (d_i <= totalMile)
				ans += v;
		}
		
		cout << "Data Set " << j << ":\n" << ans << "\n\n";
	}
    
    return 0;

}
