#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	
	int ans[5] = { 0, };
	for (int i = 0; i < n ; i++) {
		int x, y;
		cin >> x >> y;
	
		if (x == 0 || y == 0)
			ans[0]++;
		else if (x > 0 && y > 0)
			ans[1]++;
		else if (x < 0 && y > 0)
			ans[2]++;
		else if (x < 0 && y < 0)
			ans[3]++;
		else
			ans[4]++;
	}
	
	cout << "Q1: " << ans[1] << endl;
	cout << "Q2: " << ans[2] << endl;
	cout << "Q3: " << ans[3] << endl;
	cout << "Q4: " << ans[4] << endl;
	cout << "AXIS: " << ans[0] << endl;
    
    return 0;

}
