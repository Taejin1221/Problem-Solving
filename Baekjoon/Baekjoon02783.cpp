#include <cstdio>
using namespace std;

int main(){
	double x, y;
	scanf("%lf %lf", &x, &y);
	
	int n;
	scanf("%d", &n);
	double ans = x / y;
	while (n--) {
		scanf("%lf %lf", &x, &y);
		
		double temp = x / y;
		if (ans > temp) ans = temp;
	}
	
	printf("%.2f\n", ans * 1000);

    return 0;
}
