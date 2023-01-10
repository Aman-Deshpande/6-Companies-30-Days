// https://leetcode.com/problems/count-nice-pairs-in-an-array/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    int reverseNum(int n){
        int ans = 0;
        while(n){
            int ld=n%10;
            ans=ans*10+ld;

            n=n/10;
        }

        return ans;
    }
public:
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        unordered_map<int,int> m; 
    
        for(int i=0;i<n;i++)
        {
            int temp=nums[i]-reverseNum(nums[i]);  
            m[temp]++;
            count=(count+m[temp]-1)%1000000007;
        }
        return count%1000000007;
    }
};