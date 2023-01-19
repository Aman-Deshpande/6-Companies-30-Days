// https://leetcode.com/problems/distant-barcodes/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {

        if(barcodes.size() <= 1) return barcodes;

        unordered_map<int, int> m;
        for(auto it: barcodes){
            m[it]++;
        }

        priority_queue<pair<int, int>> pq;
        for(auto it: m){
            pq.push({it.second, it.first});
        }

        vector<int> res;
        while(pq.top().first>0){
            pair<int, int> p = pq.top();
            pq.pop();

            res.push_back(p.second);
            p.first--;

            pair<int, int> p2 = pq.top();
            pq.pop();

            if(p2.first>0){
                res.push_back(p2.second);
                p2.first--;
            }

            pq.push(p);
            pq.push(p2);
        }

        return res;
    }
};