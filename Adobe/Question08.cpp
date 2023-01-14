// https://leetcode.com/problems/minimum-genetic-mutation/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    bool func(string a, string b){
        bool ans = 0;
        for(int i = 0; i<8; i++){
            if(a[i]!=b[i]){
                if(ans){
                    return 0;
                }
                ans=1;
            } 
        }

        return ans;
    }
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string, int>> q;
        q.push({startGene, 0});
        int len = bank.size();

        while(!q.empty()){
            string s = q.front().first;
            int t = q.front().second;

            if(s==endGene){
                return t;
            }
            q.pop();

            int changeLen = 0;
            for(int i = 0; i<len; i++){
                if(func(s, bank[i])){
                    q.push({bank[i], t+1});
                    bank.erase(bank.begin()+i);
                    i--;
                    len--;
                }
            }
        }

        return -1;
    }
};