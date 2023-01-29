// https://leetcode.com/problems/number-of-matching-subsequences/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool solve(string s, string word){
        if(s.length() < word.length()) return false;
        int sInd = 0, wInd = 0;

        while(sInd<s.length() && wInd<word.length()){
            if(s[sInd]==word[wInd]){
                sInd++;
                wInd++;
            }else{
                sInd++;
            }
        }

        return (wInd == word.length());
    }
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string, int> m;
        int count = 0;

        for(auto str: words){
            if(m.count(str)){
                count+=m[str];
            }else{
                count+=m[str]=solve(s, str);
            }
        }

        return count;
    }
};