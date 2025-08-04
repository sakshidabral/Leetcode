struct node {
    bool isWord; 
    node* child[26]; 

    node(){
        isWord = false;
        for (int i=0; i<26; i++) {
            child[i] = nullptr;
        }
    }
};

class Trie {
public:
    node* root;

    Trie() {
        root = new node();
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
    }
    
    bool search(string word) {
        node* curr = root;
        for(auto i : word){
            if(!curr->child[i-'a']){
                return false;
            }
            curr = curr->child[i-'a'];
        }
        return curr->isWord;
    }
    
    bool startsWith(string prefix) {
        node* curr = root;
        for(auto i : prefix){
            if(!curr->child[i-'a']){
                return false;
            }
            curr = curr->child[i-'a'];
        }
        return !curr ? false : true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */