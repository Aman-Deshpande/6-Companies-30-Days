// https://leetcode.com/problems/network-delay-time/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //create adjacency list
        unordered_map<int,list<pair<int,int>>> adj;
        for(int i = 0 ; i < times.size() ; i++){
            int u = times[i][0] - 1;
            int v = times[i][1] - 1;
            int w = times[i][2];
            
            adj[u].push_back(make_pair(v,w));
        }

        //create the distance array and initialize to infinity
        vector<int> dist(n);
        for(int i = 0 ; i < n ; i++){
            dist[i] = INT_MAX;
        }

        //create a set to store <nodeDistance, node>
        set<pair<int,int>> st;
        dist[k-1] = 0;
        st.insert(make_pair(0,k-1));
        
        while(!st.empty()){
            auto front = *(st.begin());
            int nodeDistance = front.first;
            int node = front.second;
            st.erase(st.begin());
            
            //traverse the neighbours
            for(auto i : adj[node]){
                if(nodeDistance + i.second < dist[i.first]){
                    //if the entry for that neighbour already exits, then delete it.
                    auto record = st.find(make_pair(dist[i.first] , i.first));
                    
                    if(record != st.end()){
                        st.erase(record);
                    }
                    
                    dist[i.first] = nodeDistance + i.second ;
                    st.insert(make_pair(dist[i.first] , i.first));
                }
            }
        }

        int maxi = -1;
        for(int i = 0 ; i < n ; i++){
            if(dist[i] == INT_MAX)
                return -1;
            else{
                maxi = max(maxi , dist[i]);
            }
        }
        return maxi;
    }
};