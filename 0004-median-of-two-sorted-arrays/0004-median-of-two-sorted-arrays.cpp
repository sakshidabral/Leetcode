class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s = nums1.size() + nums2.size();
        vector<int> v(s);
        int p=0;
        for(int i=0;i<nums1.size();i++){
            v[p++] = nums1[i];
        }
        for(int i=0;i<nums2.size();i++){
            v[p++] = nums2[i];
        }
        sort(v.begin(),v.end());
        if(s%2!=0) return v[s/2];
        return (v[s/2] + v[s/2 - 1])/2.0;
    }
};