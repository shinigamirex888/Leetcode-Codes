#include <bits/stdc++.h>
using namespace std;



// Given a string s, find the longest palindromic subsequence's length in s.

// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.





//Recursive Approach
class Solution {
public:
    
     int helper(string s, int i, int j){
        if (i > j)      return 0;
        if (i == j)     return 1;
        
        if (s[i] == s[j]) {
            return helper(s, i + 1, j - 1) + 2;
        } else {
            return max(helper(s, i + 1, j), helper(s, i, j - 1));
        }
    }
    
    
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        return helper(s, 0,n);
    }
};









 
//Memoization Approach
 class Solution {
public:
    
     int helper(string s, int i, int j,vector<vector<int>> &dp) {
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (i > j)      return 0;
        if (i == j)     return 1;
        
        if (s[i] == s[j]) {
            dp[i][j] = helper(s, i + 1, j - 1, dp) + 2;
        } else {
            dp[i][j] = max(helper(s, i + 1, j, dp), helper(s, i, j - 1, dp));
        }
        return dp[i][j];
    }
    
    
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int> >dp( n , vector<int> (n, -1));
        return helper(s, 0, s.length() - 1,dp);
    }
};