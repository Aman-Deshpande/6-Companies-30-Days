// https://leetcode.com/problems/number-of-closed-islands/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool dfs(int x, int y, vector<vector<int>>& grid){
		if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size()){
            return false;
        }

		if(grid[x][y]==1){
            return true;
        }

		grid[x][y]=1; // imp step
        
		bool top=dfs(x-1, y, grid), left=dfs(x, y-1, grid), bottom=dfs(x+1, y, grid), right=dfs(x, y+1, grid);
		return (top && left && bottom && right);
	}
	int closedIsland(vector<vector<int>>& grid) {
		vector<vector<int>>v(grid.size(), vector<int>(grid[0].size(), 0));
		int cnt=0;
		for(int i=0; i<grid.size(); i++){
			for(int j=0; j<grid[0].size(); j++){
				if(grid[i][j]==0){
					if(dfs(i, j, grid)){
                        cnt++;
                    }
				}
			}
		}
		return cnt;
	}
};