// https://leetcode.com/problems/maximum-number-of-coins-you-can-get/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size();

        int i = n-2;
        n = n/3;
        int cnt = 0;
        int ans = 0;
        
        while(cnt<n && i>=0){
            cnt++;
            ans+=piles[i];
            i-=2;
        }

        return ans;
    }
};