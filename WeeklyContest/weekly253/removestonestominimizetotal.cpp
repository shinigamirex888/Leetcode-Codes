#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(auto it:piles)
            pq.push(it);
        while(!pq.empty() && k){
            k--;
            int ele=pq.top();
            pq.pop();
            pq.push(ele-(ele/2));
        }
        int sum=0;
        while(!pq.empty()){
            int ans=pq.top();
            sum+=ans;
            pq.pop();
        }
        return sum;
    }
};