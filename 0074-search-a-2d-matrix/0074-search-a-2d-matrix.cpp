class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size(), c = matrix[0].size();
        int i = 0, j = 0;

        while(i<r && j<c){
            if(matrix[i][j] == target) return true;

            if(matrix[i][j] < target && target <= matrix[i][c-1]) j++;
            else i++;
        }

        return false;
    }
};