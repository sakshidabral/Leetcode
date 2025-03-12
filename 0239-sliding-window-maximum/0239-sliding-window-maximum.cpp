class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;// Stores indices
        vector<int> ans;

        for(int i=0; i<n; i++) {
            // Remove elements that are out of the current window
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();

            // Remove smaller elements as they are useless
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            // Insert the current element index
            dq.push_back(i);

            // Add the maximum element for the valid window
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};