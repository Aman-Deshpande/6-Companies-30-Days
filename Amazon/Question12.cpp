// https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2, int &ans, vector<vector<int>>&dp){
        if(i>=nums1.size() || j>=nums2.size()){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int length = 0;
        if(nums1[i]==nums2[j]){
            length = 1 + solve(i+1, j+1, nums1, nums2, ans, dp);
            ans = max(ans, length);
        }
        
        solve(i+1, j, nums1, nums2, ans, dp);
        solve(i, j+1, nums1, nums2, ans, dp);
        
        return dp[i][j]=length;
    }
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size(),vector<int>(nums2.size(), -1));
        int ans = 0;
        solve(0, 0, nums1, nums2, ans, dp);
        return ans;
    }
};