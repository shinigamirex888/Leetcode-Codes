#include<bits/stdc++.h>
using namespace std;

//Only recursive approach for now.

class Solution {
public:
    int cv(int n,char last,vector<char>&v){
        if(n==0)
            return 1;
        int a=0;
        for(auto it:v){
            if(last<=it)
                a+=cv(n-1,it,v);
        }
        return a;
        
    }
    int countVowelStrings(int n) {
        vector<char>v;
        v.push_back('a');
        v.push_back('e');
        v.push_back('i');
        v.push_back('o');
        v.push_back('u');
        int ans=cv(n,'a',v);
        return ans;
    }
};