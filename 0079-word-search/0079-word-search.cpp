class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size(); 

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == word[0] && check(i,j,0,board,word)){
                    return true;
                } 
                // whenever we found first letter of word start searching from there
            }
        }

        return false;
    }

    bool check(int i, int j, int count, vector<vector<char>>& board, string word) {
        if(word.length() == count){
            return true;
        }
        // check for boundary                         // curr char is not same with word char
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] != word[count]){
            return false;
        }
        
        char temp = board[i][j]; // curr char
        board[i][j] = ' ';//visited
        
        bool ans = check(i-1,j,count+1,board,word) || 
                   check(i+1,j,count+1,board,word) ||
                   check(i,j-1,count+1,board,word) ||
                   check(i,j+1,count+1,board,word);

        board[i][j] = temp; //change into original
        
        return ans;
    }
    
};