#include <bits/stdc++.h>
using namespace std;

// Given an array of integers arr and an integer target.

// You have to find two non-overlapping sub-arrays of arr each with a sum equal target. There can be multiple answers so you have to find an answer where the sum of the lengths of the two sub-arrays is minimum.

// Return the minimum sum of the lengths of the two required sub-arrays, or return -1 if you cannot find such two sub-arrays.

class Solution
{
public:
    vector<int> miniL(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<int> presum(n, 0);
        unordered_map<int, int> mp;
        vector<int> ans(n, n + 1);
        mp[0] = -1;
        for (int i = 0; i < n; ++i)
        {
            presum[i] = i == 0 ? arr[i] : arr[i] + presum[i - 1];
            int len = arr.size() + 1;
            if (mp.find(presum[i] - target) != mp.end())
            {
                len = i - mp[presum[i] - target];
            }
            mp[presum[i]] = i;
            ans[i] = i == 0 ? len : min(ans[i - 1], len);
        }
        return ans;
    }

    int minSumOfLengths(vector<int> &arr, int target)
    {
        vector<int> pre = miniL(arr, target);
        vector<int> arrR(arr.begin(), arr.end());
        reverse(arrR.begin(), arrR.end());
        vector<int> suf = miniL(arrR, target);

        int mini = arr.size() + 1;
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i)
        {
            mini = min(mini, pre[i] + suf[n - 1 - i - 1]);
        }
        return mini == arr.size() + 1 ? -1 : mini;
    }
};