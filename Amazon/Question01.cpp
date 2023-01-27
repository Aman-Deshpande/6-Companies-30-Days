// https://leetcode.com/problems/shuffle-an-array/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> v1, v2;
    Solution(vector<int>& nums) {
        v1=v2=nums;
    }
    
    vector<int> reset() {
        return v1;
    }
    
    vector<int> shuffle() {
        int temp1 = rand()%v1.size();
        int temp2 = rand()%v1.size();
        swap(v2[temp1], v2[temp2]);

        return v2;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution* obj = new Solution(nums);
// vector<int> param_1 = obj->reset();
// vector<int> param_2 = obj->shuffle();
