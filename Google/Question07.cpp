// https://leetcode.com/problems/k-divisible-elements-subarrays/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        set<vector<int>> ans;

        for(int i  = 0; i<n; i++){
            vector<int> temp;
            int cnt = 0;
            for(int j = i; j<n; j++){
                temp.push_back(nums[j]);

                if(nums[j]%p == 0){
                    cnt++;
                }

                if(cnt>k){
                    break;
                }

                ans.insert(temp);
            }
        }   

        return ans.size();
    }
};