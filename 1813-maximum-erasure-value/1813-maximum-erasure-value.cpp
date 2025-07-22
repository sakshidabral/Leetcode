class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, currSum = 0;
        unordered_set<int> set;

        int l = 0;
        for(int r=0; r<n; r++){
            while(set.find(nums[r]) != set.end()){
                set.erase(nums[l]);
                currSum -= nums[l];
                l++;
            }

            set.insert(nums[r]);
            currSum += nums[r];
            sum = max(sum, currSum);
        }

        return sum;

    }
};