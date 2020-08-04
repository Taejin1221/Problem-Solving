// LeetCode0125_ValidPalindrome.cpp
// https://leetcode.com/problems/valid-palindrome/
// August Leetcoding Challenge Day 3
class Solution {
public:
    bool isPalindrome(string s) {
        string bareStr = "";
        
        for ( int i = 0; i < s.size(); i++ ) {
            if ( ('a' <= s[i] && s[i] <= 'z') || ( '0' <= s[i] && s[i] <= '9' ) )
                bareStr += s[i];
            else if ( ('A' <= s[i] && s[i] <= 'Z') )
                bareStr += s[i] + 32;
        }

        for ( int i = 0; i < bareStr.size() / 2; i++ )
            if ( bareStr[i] != bareStr[bareStr.size() - i - 1] )
                return false;
        return true;
    }
};
