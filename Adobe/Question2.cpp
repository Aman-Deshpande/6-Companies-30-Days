// https://leetcode.com/problems/increasing-triplet-subsequence/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& arr) {
        vector<int> temp;
        temp.push_back(arr[0]);
        int n = arr.size();

        int len = 1;
        for(int i = 1; i<n; i++){
            if(arr[i]>temp.back()){
                temp.push_back(arr[i]);
                len++;
            }else{
                int ind = lower_bound(temp.begin(), temp.end(), arr[i])-temp.begin();
                temp[ind]=arr[i];
            }
        }

        if(len>=3){
            return true;
        }

        return false;
    }
};

// Find LIS length, if length >=3 return true else false