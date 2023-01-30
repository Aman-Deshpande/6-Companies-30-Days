// https://leetcode.com/problems/top-k-frequent-words/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;

        for(auto i: words){
            m[i]++;
        }

        priority_queue<pair<int, string>> pq;

        for(auto it: m){
            pq.push({-it.second, it.first});
            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<pair<int, string>> list;
        while(!pq.empty()){
            list.push_back(pq.top());
            pq.pop();
        }

        sort(list.begin(), list.end());

        vector<string> ans;
        for(auto i: list){
            ans.push_back(i.second);
        }

        return ans;
    }
};