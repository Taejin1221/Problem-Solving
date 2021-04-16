#include <vector>

using namespace std;

int minVal = 9;
vector<int> numbers;

void dfs(int curr, int num, int& target) {
    if ( num > 8 )
        return;

    if ( curr == target )
        minVal = min( minVal, num );
    else {	
        for ( int idx = 0; idx < numbers.size(); idx++ ) {
            int number = numbers[idx];
            dfs( curr + number, num + idx + 1, target );
            dfs( curr - number, num + idx + 1, target );
            dfs( curr * number, num + idx + 1, target );
            if ( number )
                dfs( curr / number, num + idx + 1, target );
        }
    }
}

int solution(int n, int target) {
    int answer = 0;
    
    numbers.push_back( n );
    for ( int i = 1; i <= 7; i++ ) {
        dfs( 0, 0, target );
        numbers.push_back( numbers[numbers.size() - 1] * 10 + n );
    }
    
    answer = (minVal > 8) ? -1 : minVal;
    return answer;
}