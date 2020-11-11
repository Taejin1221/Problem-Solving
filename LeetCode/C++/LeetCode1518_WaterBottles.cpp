// LeetCode1518_WaterBottles.cpp
// https://leetcode.com/problems/water-bottles/
class Solution {
public:
	int numWaterBottles( int numBottles, int numExchange ) {
		int drinkBottles = numBottles;
		int emptyBottles = numBottles;
		while ( emptyBottles >= numExchange ) {
			int newBottles = emptyBottles / numExchange;
			emptyBottles %= numExchange;

			drinkBottles += newBottles;
			emptyBottles += newBottles;
		}

		return drinkBottles;
	}
};