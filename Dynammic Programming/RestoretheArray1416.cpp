#include <bits/stdc++.h>
using namespace std;

// A program was supposed to print an array of integers. The program forgot to print whitespaces and the array is printed as a string of digits s and all we know is that all integers in the array were in the range [1, k] and there are no leading zeros in the array.

// Given the string s and the integer k, return the number of the possible arrays that can be printed as s using the mentioned program. Since the answer may be very large, return it modulo 109 + 7.

//Memoization Approach
class Solution
{
public:
#define mod 1000000007
    int solution(string &s, long k, int i, vector<int> &dp)
    {
        if (i == s.size())
            return 1;
        if (s[i] == '0')
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int ans = 0;
        long num = 0;
        for (int j = i; j < s.size(); j++)
        {
            num = num * 10 + s[j] - '0';
            if (num > k)
                break;
            ans += solution(s, k, j + 1, dp);
            ans %= mod;
        }
        return dp[i] = ans;
    }

    int numberOfArrays(string s, int k)
    {
        int n = s.size();
        vector<int> dp(n, -1);
        return solution(s, k, 0, dp);
    }
};