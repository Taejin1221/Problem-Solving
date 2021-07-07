// LeetCode1689_PartitioningIntoMinimumNumberOfDeci-BinaryNumbers.cpp
// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
// LeetCode Weekly Contest 219 B
class Solution {
public:
	int minPartitions( string n ) {
		int maxVal = 0;
		for ( char& c : n )
			maxVal = max( maxVal, c - 48 );

		return maxVal;
	}
};
