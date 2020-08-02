// LeetCode0705_DesignHashSet.cpp
// https://leetcode.com/problems/design-hashset/
// August Leetcoding Challenge Day 2
class MyHashSet {
public:
	bool table[1'000'001];
	MyHashSet() {
		fill( table, table + 1'000'001, false );
	}

	void add( int key ) {
		table[key] = true;
	}

	void remove( int key ) {
		table[key] = false;
	}

	bool contains( int key ) {
		return table[key];
	}
};