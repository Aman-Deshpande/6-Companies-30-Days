// https://leetcode.com/problems/max-area-of-island/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    void solve(vector<vector<int>> &grid, int i, int j, int &area){
        if(!(i<grid.size() && i>=0 && j<grid[0].size() && j>=0 && grid[i][j]==1)){
            return;
        }
        
        area++;

        grid[i][j]=0;

        solve(grid, i, j-1, area);
        solve(grid, i, j+1, area);
        solve(grid, i-1, j, area);
        solve(grid, i+1, j, area);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;
        int maxArea = 0;

        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j]==1){
                    solve(grid, i, j, area);
                    maxArea = max(area, maxArea);
                    area=0;
                }
            }
        }

        return maxArea;
    }
};