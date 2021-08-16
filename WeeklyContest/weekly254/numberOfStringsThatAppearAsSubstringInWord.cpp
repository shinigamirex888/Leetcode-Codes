#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        set<string>s;
        int n=word.size();
        for(int i=0;i<n;i++){
            for(int j=n-i;j>=1;j--){
                s.insert(word.substr(i,j));
            }
        }
        int ans=0;
        for(auto i:patterns){
            if(s.count(i)==0) continue;
            else ans++;
        }
        return ans;
    }
};