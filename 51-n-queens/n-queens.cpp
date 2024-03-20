class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> board(n,vector<char>(n,'.'));
        solve(0,ans,board,n);
        return ans;
    }
    void solve(int col, vector<vector<string>>& ans, vector<vector<char>>& board, int n){
        if(col==n){
            addSol(ans,board,n);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,ans,board,n);
                board[row][col]='.';
            }
        }
    }
    bool isSafe(int row, int col, vector<vector<char>>& board, int n){
        int x=row,y=col;
        while(y>=0){
            if(board[x][y]=='Q') return false;
            y--;
        }
        x=row,y=col;
        while(x>=0 && y>=0){
            if(board[x][y]=='Q') return false;
            y--;
            x--;
        }
        x=row,y=col;
        while(x<n && y>=0){
            if(board[x][y]=='Q') return false;
            y--;
            x++;
        }
        return true;
    }
    void addSol(vector<vector<string>>& ans, vector<vector<char>>& board, int n){
        vector<string> v;
        for(int i=0;i<n;i++){
            string s="";
            for(int j=0;j<n;j++){
                s.push_back(board[i][j]);
            }
            v.push_back(s);
        }
        ans.push_back(v);
    }
};