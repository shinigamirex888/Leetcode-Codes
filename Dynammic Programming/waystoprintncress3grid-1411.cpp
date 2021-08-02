#include<bits/stdc++.h>
using namespace std;

// You have a grid of size n x 3 and you want to paint each cell of the grid with exactly one of the three colors:
//  Red, Yellow, or Green while making sure that no two adjacent cells have the same color 
//  (i.e., no two cells that share vertical or horizontal sides have the same color).

// Given n the number of rows of the grid, 
// return the number of ways you can paint this grid. 
// As the answer may grow large, the answer must be computed modulo 109 + 7.

class Solution {
public:
    int numOfWays(int n) {
        long  c3=6;                    //T.C=O(n)
        long  c2=6;                    //S.C=O(1)
        long mod=1e9+7;               
        for(int i=2;i<=n;i++){
            long temp=c3;
            c3=(2*c2+2*c3)%mod;
            c2=(2*temp+3*c2)%mod;
        }
        return (c3+c2)%mod;
    }
};