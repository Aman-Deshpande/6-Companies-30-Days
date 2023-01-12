// https://leetcode.com/problems/number-of-matching-subsequences/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasMatches(string &curr, string &s) {
        int ind = 1;
        int i = s.find(curr[0]);
        if (i == -1)
            return false;

        while (ind < curr.length()) {
            i = s.find(curr[ind], i + 1);
            if (i == -1){
                return false;
            }

            ind++;
        }

        return true;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        for (string str : words){
            if (hasMatches(str, s))
                count++;
        }
        
        return count;
    }
};