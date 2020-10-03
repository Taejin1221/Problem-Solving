// LeetCode1603_DesignParkingSystem.cpp
// https://leetcode.com/problems/design-parking-system/
class ParkingSystem {
public:
	int spaces[4];
	ParkingSystem( int big, int medium, int small ) {
		spaces[1] = big;
		spaces[2] = medium;
		spaces[3] = small;
	}

	bool addCar( int carType ) {
		if ( spaces[carType] ) {
			spaces[carType]--;

			return true;
		} else
			return false;
	}
};