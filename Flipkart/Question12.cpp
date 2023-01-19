// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> st;
        string str = "";

        for(int i = 0; i<s.length(); i++){
            str+=s[i];
            if(i>=k) str.erase(0, 1);
            if(str.size() >= k) st.insert(str);
        }

        if(st.size() == pow(2, k)){
            return true;
        }

        return false;
    }
};