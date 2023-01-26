// https://leetcode.com/problems/matrix-block-sum/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> vt(m+1,vector<int>(n+1,0));
        for ( int i = 0; i < m; i++ ) 
            for ( int j = 0; j < n; j++ )
                vt[i+1][j+1] = mat[i][j] - vt[i][j] + vt[i][j+1] +vt[i+1][j];
 
        vector<vector<int>> res(m,vector<int>(n,0));
        
        for ( int i = 0; i < m; i++ ) {
            for ( int j = 0; j < n; j++ ) {
                int i1 = max(0, i-k);
                int j1 = max(0, j-k);
                int i2 = min(m,i+k+1);
                int j2 = min(n,j+k+1);
                res[i][j] = vt[i2][j2] - vt[i2][j1] - vt[i1][j2] +vt[i1][j1];
            }
        }
        return res;
    }
};