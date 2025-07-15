class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int min = INT_MAX, sum = 0;

        for(int i=0; i<n ;i++){
            if(prices[i] < min){
                min = prices[i];
            }
            else if(i+1<n && prices[i] > prices[i+1]){
                sum += prices[i] - min;
                min = INT_MAX;
            }
        }

        if(min != INT_MAX && prices[n-1] > min) {
            sum += prices[n-1] - min;
        }

        return sum;
    }
};