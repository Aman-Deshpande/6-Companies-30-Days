// https://leetcode.com/problems/combination-sum-iii/description/

#include<bits./stdc++.h>
using namespace std;

class Solution {
    private:

    void solve(int k, int n, int i, vector<vector<int>> &ans, vector<int> &v){
        if(k==0 && n==0){
            ans.push_back(v);
            return;
        }

        if(i>9){
            return;
        }

        v.push_back(i); // take
        solve(k-1, n-i, i+1, ans, v);
        
        v.pop_back(); // not take
        solve(k, n, i+1, ans, v);

    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;

        solve(k, n, 1, ans, v);

        return ans;
    }
};