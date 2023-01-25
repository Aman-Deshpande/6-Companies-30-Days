// https://leetcode.com/problems/random-pick-with-weight/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> s;
    Solution(vector<int>& w) {
        for(int i: w){
            if(s.empty()){
                s.push_back(i);
            }else{
                s.push_back(i + s.back());
            }
        }
    }
    
    int pickIndex() {
        int x = s.back();
        int ind = rand()%x;
        auto it = upper_bound(s.begin(), s.end(), ind);
        return it-s.begin();
    }
};


// Your Solution object will be instantiated and called as such:
// Solution* obj = new Solution(w);
// int param_1 = obj->pickIndex();
 