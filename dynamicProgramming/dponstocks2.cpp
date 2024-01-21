#include<bits/stdc++.h>
using namespace std;

class dponstocks{
public:
     //memoized
    int func(int i, bool flag, vector<int> &prices, 
    vector<vector<int>> &dp){
        if(i==prices.size()) return 0;
        if(dp[i][flag]!=-1) return dp[i][flag];
        int profit = 0;
        if(flag){
            int take = func(i+1, false, prices, dp) - prices[i];
            int nottake = func(i+1, true, prices, dp);
            profit = max(take, nottake);
        }
        else{
            int sell = func(i+1, true, prices, dp) + prices[i];
            int notsell = func(i+1, false, prices, dp);
            profit = max(sell, notsell);
        }
        return dp[i][flag] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return func(0, true, prices, dp);
    }
    //tabulation
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2, 0));
        
        dp[n][0] = dp[n][1] = 0;
        int profit = 0;
        for(int i= n-1; i>=0 ;i--){
            for(int buy= 0; buy<=1; buy++){
                if(buy){
                    profit = max(dp[i+1][0]-prices[i], dp[i+1][1]);
                }
                else{
                    profit = max(dp[i+1][1]+prices[i], dp[i+1][0]);
                }
                dp[i][buy] = profit;
            }
        }
        return profit;
    }
    //space optimized
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(2, 0), curr(2, 0);
        
        curr[0] = curr[1] = 0;
        int profit = 0;
        for(int i= n-1; i>=0 ;i--){
            for(int buy= 0; buy<=1; buy++){
                if(buy){
                    profit = max(ahead[0]-prices[i], ahead[1]);
                }
                else{
                    profit = max(ahead[1]+prices[i], ahead[0]);
                }
                curr[buy] = profit;
            }
            ahead = curr;
        }
        return ahead[1];
    }
};