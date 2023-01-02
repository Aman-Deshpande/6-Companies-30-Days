// https://leetcode.com/problems/rotate-function/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long sum = 0;
        long original = 0;
        int n = nums.size();

        for(int i = 0; i<n; i++){
            sum+=nums[i];
            original+=i*nums[i]; // when no rotation
        }

        long maximum = original;

        // start calculating value of rotation func for each rotation
        for(int i = n-1; i>=0; i--){
            original += sum - (n*nums[i]); // important
            maximum = max(maximum, original);
        }

        return maximum;
    }
};