// LeetCode0771_JewelsAndStones.cpp
class Solution {
public:
	int numJewelsInStones(string J, string S) {
		int size_J = J.length();
		int size_S = S.length();
		int count = 0;

		for (int i = 0; i < size_J; i++) {
			char jewel = J[i];
			for (int j = 0; j < size_S; j++)
				if (jewel == S[j]) count++;
		}

		return count;
	}

	int numJewelsInStones(string J, string S) {
		int count = 0;
		int size_J = J.length(), size_S = S.length();

		vector<int> hashTable (59);
		for (int i = 0; i < size_S; i++)
			hashTable[S[i] - 65]++;

		for (int i = 0; i < size_J; i++)
			count += hashTable[J[i] - 65];

		return count;
	}
};