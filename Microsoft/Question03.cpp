// https://leetcode.com/problems/bulls-and-cows/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int n=secret.size();
        int bull=0,cow=0;
        map<int,int> mp1;
        map<int,int> mp2;
        for(int i=0;i<n;i++)
        {
            if(secret[i]==guess[i])
                bull++;
            else
            {
                mp1[secret[i]-'0']++;
                mp2[guess[i]-'0']++;
            }
            
        }

        for(auto it:mp1)
        {
            if(mp2.find(it.first)!=mp2.end()){
                cow+=min(mp2[it.first],it.second);
            }
            
        }
        string s="";
        s=to_string(bull)+"A"+to_string(cow)+"B";
        return s;
    }
};