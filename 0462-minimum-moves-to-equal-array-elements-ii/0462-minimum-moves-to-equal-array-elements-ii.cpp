class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int val = nums[n/2];

        int op = 0;
        for(int num : nums){
            op += abs(num - val);
        }

        return op;
    }
};