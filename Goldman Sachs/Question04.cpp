// https://leetcode.com/problems/number-of-boomerangs/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    int findDist(vector<int> &p1, vector<int> &p2){
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        int count = 0;

        for(int i = 0; i<n; i++){
            map<int, int> m;
            for(int j = 0; j<n; j++){
                if(i==j) continue;

                int dist = findDist(points[i], points[j]);
                if(m.find(dist)!=m.end()){
                    count += m[dist]*2;
                }

                m[dist]++;
            }
        }

        return count;
    }
};
