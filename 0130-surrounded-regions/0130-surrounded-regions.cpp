class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        
        for(int i=0;i<m;i++){ // first and last row
            if(board[i][0] == 'O'){
                dfs(board,i,0,m,n);
            }
            if(board[i][n-1]=='O'){
                dfs(board,i,n-1,m,n);
            }
        }
        
        for(int i=0;i<n;i++){ //first and lasst col
            if(board[0][i] == 'O'){
                dfs(board,0,i,m,n);
            }
            if(board[m-1][i]=='O'){
                dfs(board,m-1,i,m,n);
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 'O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='$') {
                    board[i][j] = 'O';
                }
            }
        }
    }
    void dfs(vector<vector<char>>& board, int i, int j, int m, int n){
        if(i>=m || i<0 || j<0 || j>=n || board[i][j]!='O'){
            return;
        }

        board[i][j] = '$'; // to indicate its connected with boundary
        
        dfs(board,i+1,j,m,n);
        dfs(board,i-1,j,m,n);
        dfs(board,i,j+1,m,n);
        dfs(board,i,j-1,m,n);
    }
};