#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        bool ans=isSub(s,t,n,m);
        return ans;
    }
    bool isSub(string s,string t,int n,int m){
        if(n==0)
            return true;
        if(m==0)
            return false;
        if(s[n-1]==t[m-1])
            return isSub(s,t,n-1,m-1);
        return isSub(s,t,n,m-1);
    }
};

//Two -pointers Approach
