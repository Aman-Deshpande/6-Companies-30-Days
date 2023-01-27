// https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int ans = 1;
    private:
    void solve(string str, int ind, vector<string> &temp, unordered_set<string> &st){
        if(ind == str.length()){
            int l = temp.size();
            ans = max(l, ans);
            return;
        }

        string s = "";
        for(int i = ind; i<str.length(); i++){
            s.push_back(str[i]);
            if(!st.count(s)){
                temp.push_back(s);
                st.insert(s);

                solve(str, i+1, temp, st);
                
                // backtrack
                st.erase(s);
                temp.pop_back();
            }
        }
    }
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        vector<string> temp;

        solve(s, 0, temp, st);
        return ans;
    }
};