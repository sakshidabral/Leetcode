class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int cap) {
        vector<int> sum(1001);
        int maxi = 0;

        for(auto v : trips){
            sum[v[1]] += v[0];
            sum[v[2]] -= v[0];
            maxi = max(maxi, v[2]);
        }

        if(sum[0] > cap) return false;

        for(int i=1; i<=maxi; i++){
            sum[i] = sum[i-1] + sum[i];
            if(sum[i] > cap) return false;
        }
        
        return true;
    }
};