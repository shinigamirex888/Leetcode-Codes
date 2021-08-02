// Alice and Bob take turns playing a game, with Alice starting first.

// Initially, there is a number n on the chalkboard. On each player's turn, that player makes a move consisting of:

// Choosing any x with 0 < x < n and n % x == 0.
// Replacing the number n on the chalkboard with n - x.
// Also, if a player cannot make a move, they lose the game.

// Return true if and only if Alice wins the game, assuming both players play optimally.
#include<bits/stdc++.h>
using namespace std;

// Recursive solution
class Solution
{
public:
    bool solution(int n)
    {
        if (n == 1)
            return false;
        for (int i = 1; i < n; i++)
        {
            if (n % i == 0)
            {
                if (solution(n - i) == 0)
                {
                    return 1;
                }
            }
        }
        return 0;
    }
    bool divisorGame(int n)
    {
        return solution(n);
    }
};

//Memoization solution
class Solution {
public:
    int solution(int n,vector<int> &v){
        if(n==1)
            return 0;
        if(v[n]!=-1)
            return v[n];
        
        for(int i=1;i<n;i++){
            if(n%i==0){
                if(solution(n-i,v)==0){
                    return v[n]=1;
                }
            }
        }
        return v[n]=0;
    }
    int divisorGame(int n) {
        vector<int>v(n+1,-1);
        return solution(n,v);   
    }
};