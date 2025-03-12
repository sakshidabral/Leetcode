class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n < 1) return 0;
        sort(nums.begin(), nums.end());
        int maxSize = 1, currSize = 1;
        for(int i=1;i<n;i++){
            if(nums[i] == nums[i - 1]) continue;
            if(nums[i] == nums[i-1]+1) currSize++;
            else {
                maxSize = max(maxSize, currSize);
                currSize = 1;
            }
        }
        maxSize = max(maxSize, currSize);
        return maxSize;
        /*
        0 1 0 2 
        0 0 1 2
        op 2, ep 3
        */

    }
};