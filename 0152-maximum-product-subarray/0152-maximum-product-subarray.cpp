class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int minn = 1, maxx = 1;
        int ans = INT_MIN;

        for(int i=0; i<n; i++){
            if(nums[i] < 0){
                swap(maxx, minn);
            }

            maxx = max(maxx * nums[i], nums[i]);
            minn = min(minn * nums[i], nums[i]);

            ans = max(ans, maxx);
        }

        return ans;
    }
};