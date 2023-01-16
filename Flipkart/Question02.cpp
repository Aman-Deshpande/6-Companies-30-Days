// https://leetcode.com/problems/shopping-offers/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans=INT_MAX;
    
    void solve(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int n, int k){
        
        if(!n){
            ans=min(ans, k);
        }
        
        if(k>ans) return;
        
        for(int i=0; i<special.size(); i++){
            bool suff=true;
            int s=0;
            
            for(int j=0; j<needs.size(); j++){
                if(needs[j]<special[i][j]) {
                    suff=false;
                }
            }
            
            if(suff){ 
                // taking the offer
                for(int j=0; j<needs.size(); j++){
                    needs[j]-=special[i][j];
                    s+=special[i][j];
                }

                solve(price, special, needs, n-s, k+special[i].back());
                
                // not taking the offer
                for(int j=0; j<needs.size(); j++){
                    needs[j]+=special[i][j];
                }
            }
        }
        
        for(int i=0; i<needs.size(); i++){
            k+=needs[i]*price[i];
        }
        
        ans=min(ans, k);
        return;
    }
    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        
        int n=0;
        
        for(auto a:needs) n+=a;
        
        solve(price, special, needs, n, 0);
        return ans;
    }
};