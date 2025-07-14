class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int n = 9;
        bool row[n][n] = {0};
        bool col[n][n] = {0};
        bool subGrid[n][n] = {0};

        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                if(board[r][c] == '.') continue;

                int num = board[r][c] - '0' - 1;
                int sub = (r/3) * 3 + (c/3);

                if(row[r][num] || col[c][num] || subGrid[sub][num]){
                    return false;
                }

                row[r][num] = 1;
                col[c][num] = 1;
                subGrid[sub][num] = 1;
            }
        }

        return true;
    }
};