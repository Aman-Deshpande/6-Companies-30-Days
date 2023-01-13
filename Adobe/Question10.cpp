// https://leetcode.com/problems/maximum-matrix-sum/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        long long sum = 0;
        int negCount = 0;
        int smallestMin = INT_MAX;
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                sum += abs(matrix[i][j]); //Add all the numbers
                
                if(matrix[i][j] < 0)
                    negCount++; //keep track of count of -ve numbers
                
				//keep track of the smallest number which can be negative
                smallestMin = min(smallestMin, abs(matrix[i][j]));
            }
        }
        
        if(negCount%2 == 0){
            return sum;
        }

        return sum-2*smallestMin;
    }
};