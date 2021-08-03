#include <bits/stdc++.h>
using namespace std;


// Alice and Bob continue their games with piles of stones. There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.

// Alice and Bob take turns, with Alice starting first. On each player's turn, that player can take 1, 2 or 3 stones from the first remaining stones in the row.

// The score of each player is the sum of values of the stones taken. The score of each player is 0 initially.

// The objective of the game is to end with the highest score, and the winner is the player with the highest score and there could be a tie. The game continues until all the stones have been taken.

// Assume Alice and Bob play optimally.

// Return "Alice" if Alice will win, "Bob" if Bob will win or "Tie" if they end the game with the same score.



//Recursive Approach
class Solution {
public:
    
    int solution(vector<int> &s,int ind){
        if(ind>=s.size())
            return 0;
        else
        {
            int ans=INT_MIN;
            ans=max(ans,s[ind]-solution(s,ind+1));
            if(ind+1 <s.size())
                ans=max(ans,s[ind]+s[ind+1]-solution(s,ind+2));
            if(ind+2 <s.size())
                ans=max(ans,s[ind]+s[ind+1]+s[ind+2]-solution(s,ind+3));
            return ans;
        }
    }
    
    string stoneGameIII(vector<int>& stoneValue) {
        int t=solution(stoneValue,0);
        if(t>0)
            return "Alice";
        else if(t==0)
            return "Tie";
        else
            return "Bob";
            
    }
};



//Memoization Approach
class Solution {
public:
    
    int solution(vector<int> &s,int ind,vector<int> &dp){
        if(ind>=s.size())
            return 0;
        if(dp[ind]!=3000)
            return dp[ind];
        else
        {
            int ans=INT_MIN;
            ans=max(ans,s[ind]-solution(s,ind+1,dp));
            if(ind+1 <s.size())
                ans=max(ans,s[ind]+s[ind+1]-solution(s,ind+2,dp));
            if(ind+2 <s.size())
                ans=max(ans,s[ind]+s[ind+1]+s[ind+2]-solution(s,ind+3,dp));
            return dp[ind]=ans;
        }
    }
    
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int>dp(50001,3000);
        int t=solution(stoneValue,0,dp);
        if(t>0)
            return "Alice";
        if(t==0)
            return "Tie";
    
        return "Bob";
            
    }
};