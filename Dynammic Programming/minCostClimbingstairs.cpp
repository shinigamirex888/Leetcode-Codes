#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    
    int mc(vector<int>&cost,int n,vector<int>& dp){
        if(n<0)
            return 0;
        if(n==0 || n==1){
            return cost[n];
        }
        if(dp[n]!=-1)
            return dp[n];
        return dp[n]=cost[n]+min(mc(cost,n-1,dp),mc(cost,n-2,dp));
    }
    
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
       // int ans=min(mc(cost, n-1),mc(cost, n-2));
        vector<int>dp(n,-1);
        int ans=min(mc(cost, n-1,dp),mc(cost, n-2,dp));
        return ans;
    }
};