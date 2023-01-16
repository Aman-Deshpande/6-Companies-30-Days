// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<bool> vis;
    bool solve(vector<int> &nums, int i, int n, int k, int currSum, int targetSum){
        if(k==1){
            return true;
        }

        if(i==n){
            return false;
        }

        if(currSum == targetSum){
            return solve(nums, 0, n, k-1, 0, targetSum);
        }

        for(int j = i; j<n; j++){
            if(!vis[j] && currSum+nums[j]<=targetSum){
                vis[j]=true;
                currSum+=nums[j];

                if(solve(nums, j+1, n, k, currSum, targetSum)){
                    return true;
                }

                vis[j]=false;
                currSum-=nums[j];
            }
        }

        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;

        for(auto i: nums){
            sum+=i;
        }

        if(sum%k!=0){
            return false;
        }

        vis.assign(n, false);

        int targetSum = sum/k;
        return solve(nums, 0, n, k, 0, targetSum);
    }
};