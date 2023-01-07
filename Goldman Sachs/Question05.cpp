// https://leetcode.com/problems/split-array-into-consecutive-subsequences/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
     bool isPossible(vector<int>& nums) {
        //freq. map denotes no. of elements left to be placed in subseq.
        unordered_map<int,int> freq;
        for(int x: nums) freq[x]++;
        
        //hypothetical map which denotes the "next" number req. by subsequences.
        unordered_map<int,int> need;
        
        for(int i: nums){
            //all occurences of cur num is already taken
            if(freq[i] == 0) continue;
            
            if(need[i] > 0){ // "i" can be a part of some existing subseq.
                need[i]--;
                freq[i]--;
                
                need[i+1]++; //next req. num is now "N+1"
            }
            
            //try creating a new sub. of length atleast three
            else if(freq[i]>0 && freq[i+1]>0 && freq[i+2]>0){
                freq[i]--;
                freq[i+1]--;
                freq[i+2]--;
                
                //next num needed in subseq.
                need[i+3]++;
            }
            
            //above both condtn is false
            else{
                return false;
            }
        }
        
        return true;
    }
};