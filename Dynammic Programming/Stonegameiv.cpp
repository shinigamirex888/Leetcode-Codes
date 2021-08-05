#include <bits/stdc++.h>
using namespace std;



// Alice and Bob take turns playing a game, with Alice starting first.

// Initially, there are n stones in a pile.  On each player's turn, that player makes a move consisting of removing any non-zero square number of stones in the pile.

// Also, if a player cannot make a move, he/she loses the game.

// Given a positive integer n. Return True if and only if Alice wins the game otherwise return False, assuming both players play optimally.



//Recursive Approach
class Solution {
public:
    
    int solution(int n){
        if(n<=0)
            return 0;
        for(int i=1;i*i<=n;i++){
            if(solution(n-(i*i))==0)
                return 1;
        }
        return 0;
    }
    
    bool winnerSquareGame(int n) {
        bool ans=solution(n);
        return ans;
    }
};

//Memoization Approach
class Solution {
public:
    
    int solution(int n,vector<int> &dp){
        if(n<=0)
            return 0;
        if(dp[n] !=-1)
            return dp[n];
        for(int i=1;i*i<=n;i++){
            if(solution(n-(i*i),dp)==0)
                return dp[n]=1;
        }
        return dp[n]=0;
    }
    
    bool winnerSquareGame(int n) {
        vector<int>dp(n+2,-1);
        bool ans=solution(n,dp);
        return ans;
    }
};