#include <bits/stdc++.h>
using namespace std;


// Alice and Bob continue their games with piles of stones.  There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].  The objective of the game is to end with the most stones. 

// Alice and Bob take turns, with Alice starting first.  Initially, M = 1.

// On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M.  Then, we set M = max(M, X).

// The game continues until all the stones have been taken.

// Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.



//Recursive Approach
class Solution {
public:
    int solution(int i,int M,vector<int>&p){
        if(i>=p.size())
            return 0;
        
        int tot=0;
        int ans=INT_MIN;
        for(int j=0;j<2*M;j++){
            if(i+j<p.size())
                tot+=p[i+j];
            ans=max(ans,tot-solution(i+j+1,max(M,j+1),p));
        }
        return ans;
    }
    
    
    int stoneGameII(vector<int>& piles) {
        int sum=0;
        for(auto it:piles)
            sum+=it;
        int diff=solution(0,1,piles);
        return (sum+diff)/2;
    }
};



//Memoization Approach
class Solution {
public:
    int dp[101][201];
    int solution(int i,int M,vector<int>&piles){
        if(i>=piles.size())
            return 0;
        if(dp[i][M]!=-1)
            return dp[i][M];
        int tot=0;
        int ans=INT_MIN;
        for(int j=0;j<2*M;j++){
            if(i+j<piles.size())
                tot+=piles[i+j];
            ans=max(ans,tot-solution(i+j+1,max(M,j+1),piles));
        }
        return dp[i][M]=ans;
    }
    
    
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof dp);
        int sum=0;
        for(auto it:piles)
            sum+=it;
        int diff=solution(0,1,piles);
        return (sum+diff)/2;
    }
};