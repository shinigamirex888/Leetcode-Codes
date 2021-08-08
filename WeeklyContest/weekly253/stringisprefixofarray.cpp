#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int j=0;
        for(int i=0;i<words.size();i++){
            int curr=words[i].size();
            string ss=s.substr(j,curr);
            if(ss==words[i]){
                j+=curr;
                if(j==s.size()) return true;
            }else{
                return false;
            }
        }
        return j==s.size();
    }
};