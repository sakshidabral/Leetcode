class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minn = prices[0];
        int profit = 0;
        for(int i=1;i<n;i++){
            if(prices[i] < minn)
                minn = prices[i];
            profit = max(profit, prices[i]-minn);
        }
        return profit;
    }
};