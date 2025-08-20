class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int count = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                count += check(i, j, mat, dp);
            }
        }

        return count;
    }

    int check(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp){
        if(i<0 || j<0) {
            return 0;
        }
        if(mat[i][j] == 0){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];

        int left = check(i, j-1, mat, dp);
        int up = check(i-1, j, mat, dp);
        int ul = check(i-1, j-1, mat, dp); // diagonal

        return dp[i][j] = 1 + min({left, up, ul});
    }
};