// https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        int n = special.size();
        int ans = 0;

        for(int i = 0; i<n; i++){
            if(i==0){
                ans=max(ans, special[0]-bottom);
            }else{
                ans=max(ans, special[i]-special[i-1]-1);
            }
        } 

        ans = max(ans, top-special[n-1]);

        return ans;  
    }
};