class Solution {
public:
    struct node {
        bool isWord; 
        node* child[26]; 
        //string fullWord;

        node(){
            isWord = false;
            for (int i=0; i<26; i++) {
                child[i] = nullptr;
            }
        }
    };

    node* root;
    vector<string> res;
    unordered_set<string> added;

    Solution() {
        root = new node();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        for(int i = 0; i < words.size(); i++){
            insert(words[i]);
        }

        int m = board.size(), n = board[0].size();
        string path = "";
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                dfs(board, visited, i, j, root, path);
            }
        }

        return res;
    }

    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, node* node, string& path){
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return;
        if (visited[i][j]) return;

        char c = board[i][j];
        if (!node->child[c - 'a']) return;

        node = node->child[c - 'a'];
        path.push_back(c);
        visited[i][j] = true;

        if (node->isWord && added.find(path) == added.end()) {
            res.push_back(path);
            added.insert(path);  // avoid duplicates
        }

        dfs(board, visited, i+1, j, node, path);
        dfs(board, visited, i-1, j, node, path);
        dfs(board, visited, i, j+1, node, path);
        dfs(board, visited, i, j-1, node, path);

        visited[i][j] = false;
        path.pop_back();
    }

    
    void insert(string word) {
        node* curr = root;
        for(char i : word){
            if(!curr->child[i-'a']){
                curr->child[i-'a'] = new node();
            }

            curr = curr->child[i-'a'];
        }

        curr->isWord = true;
        //curr->fullWord = word;
    }
    
};