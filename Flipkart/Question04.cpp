// https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(int n, int k){
        if(n==1){
            return 0;
        }

        int a = (solve(n-1, k)+k)%n;
        return a;
    }
public:
    int findTheWinner(int n, int k) {
        return solve(n, k)+1;
    }
};