class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int x=matrix.size(), y=matrix[0].size();
        int l=0, h=y-1;
        while(l<x && h>-1){
            int mid=matrix[l][h];
            if(mid==target) return true;
            if(target < mid) h--;
            else l++;
        }
        return false;
    }
};