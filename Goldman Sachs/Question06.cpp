// https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map <int, int> map;
        int res = INT_MAX, flag=0;
        int n = cards.size();

        for(int i = 0; i<n; i++){
            if(map.find(cards[i])!=map.end()){
                res = min(res, (i-map[cards[i]])+1 );
                flag = 1;
            }
            map[cards[i]] = i; 
        }

        return (flag == 0) ? -1 : res;
    }
};