class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int l = 0, r = height.size()-1;

        while(l < r){
            int h = min(height[l], height[r]);
            int w = r - l;
            int water = h * w;

            if(water > max) max = water;
            else if(height[l] < height[r]) l++;
            else r--;
        }

        return max;
    }
};