#include <bits/stdc++.h>
using namespace std;


// Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

// In one step, you can delete exactly one character in either string.


//Recursive solution
class Solution {
public:
    
    int minDis(int i,int j,string &s1,string &s2){
        if(i==s1.size() && j==s2.size())
            return 0;
        if(i==s1.size())
            return s2.size()-j;
        if(j==s2.size())
            return s1.size()-i;
        if(s1[i]==s2[j])
            return minDis(i+1,j+1,s1,s2);
        return 1+min(minDis(i+1,j,s1,s2),minDis(i,j+1,s1,s2));
    }
    
    int minDistance(string word1, string word2) {
        int dist=minDis(0,0,word1,word2);
        return dist;
    }
};



//Memoization solution
class Solution {
public:
    
    int minDis(int i,int j,string &s1,string &s2,vector<vector<int>> &dp){
        if(i==s1.size() && j==s2.size())
            return 0;
        if(i==s1.size())
            return s2.size()-j;
        if(j==s2.size())
            return s1.size()-i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j])
            return dp[i][j]= minDis(i+1,j+1,s1,s2,dp);
        return dp[i][j]=1+min(minDis(i+1,j,s1,s2,dp),minDis(i,j+1,s1,s2,dp));
    }
    
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int dist=minDis(0,0,word1,word2,dp);
        return dist;
    }
};