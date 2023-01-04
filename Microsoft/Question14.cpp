// https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(), nums.end());
        sort(numsDivide.begin(), numsDivide.end());

        int cnt = 0;
        int gcd = numsDivide[0];

        for(int i = 1; i<numsDivide.size(); i++){
            gcd = __gcd(gcd, numsDivide[i]);
        }

        if(nums[0]>gcd){
            return -1;
        }

        for(int i = 0; i<nums.size(); i++){
            if(nums[i]%gcd==0){
                return cnt;
            }
            cnt++;
        }

        return -1;
    }
};