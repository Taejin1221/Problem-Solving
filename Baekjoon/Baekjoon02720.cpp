#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	
	while (n--) {
		int change;
		cin >> change;
		
		int ans[4] = { 0, };

		ans[0] = change / 25;
		change %= 25;
		
		ans[1] = change / 10;
		change %= 10;
		
		ans[2] = change / 5;
		change %= 5;
		
		ans[3] = change / 1;
		change %= 1;
		
		cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << ' ' << ans[3] << '\n';
	}
    
    return 0;

}
