// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp;
        temp=nums;
        sort(temp.begin(), temp.end());

        int n = nums.size();
        int i, j;
        for(i = 0; i<n; i++){
            if(temp[i]!=nums[i]){
                break;
            }
        }

        for(j = n-1; j>=0; j--){
            if(temp[j]!=nums[j]){
                break;
            }
        }

        int len = 0;
        for(int k = i; k<j; k++){
            len++;
        }

        return len;
    }
};