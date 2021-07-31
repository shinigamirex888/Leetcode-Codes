#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int cs(int n,vector<int>& v){
         if(n<1)
            return 0;
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        if(v[n]!=-1)
            return v[n];
        return v[n]=cs(n-1,v)+cs(n-2,v);
    }
    int climbStairs(int n) {
        vector<int>v(n+1,-1);
        int ans=cs(n,v);
        return ans;
    }
};