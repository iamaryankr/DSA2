#include<bits/stdc++.h>
using namespace std;

class dponstock4{
public:
    class Solution {
public:
    int func(int i, bool flag, int cap, vector<int> &prices, 
    vector<vector<vector<int>>> &dp){
        if(i==prices.size()) return 0;
        if(cap==0) return 0;
        if(dp[i][flag][cap]!=-1) return dp[i][flag][cap];
        int profit = 0;
        if(flag){
            int take = func(i+1, false, cap, prices, dp) - prices[i];
            int nottake = func(i+1, true, cap, prices, dp);
            profit = max(take, nottake);
        }
        else{
            int sell = func(i+1, true, cap-1, prices, dp) + prices[i];
            int notsell = func(i+1, false, cap, prices, dp);
            profit = max(sell, notsell);
        }
        return dp[i][flag][cap] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp
        (n, vector<vector<int>> (2, vector<int> (k+1, -1)));
        return func(0, true, k, prices, dp);
    }
};
};