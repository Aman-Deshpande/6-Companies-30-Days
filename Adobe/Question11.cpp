// https://leetcode.com/problems/stock-price-fluctuation/description/

#include<bits/stdc++.h>
using namespace std;

class StockPrice {
public:
    unordered_map<int, int> map;
    priority_queue<pair<int, int>> pq; 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_min;

    int currentPrice = 0;
    int currentTimeStamp = 0;

    StockPrice() {}
    
    void update(int timestamp, int price) {
        map[timestamp]=price;

        pq.push({price, timestamp});
        pq_min.push({price, timestamp});

        if(timestamp >= currentTimeStamp){
            currentTimeStamp = timestamp;
            currentPrice = price;
        } 

        while(map[pq.top().second] != pq.top().first){
            pq.pop();
        }

        while(map[pq_min.top().second] != pq_min.top().first){
            pq_min.pop();
        }
    }
    
    int current() {
        return currentPrice;
    }
    
    int maximum() {
        return pq.top().first;
    }
    
    int minimum() {
        return pq_min.top().first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */