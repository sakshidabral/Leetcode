class Solution {
private:
    void dfs(string word, const string& beginWord, 
    unordered_map<string, vector<string>>& parent, 
    vector<string>& path, vector<vector<string>>& res) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            res.push_back(temp);
            return;
        }
        for (const auto& p : parent[word]) {
            path.push_back(p);
            dfs(p, beginWord, parent, path, res);
            path.pop_back();
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, 
    vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return {};
        unordered_map<string, vector<string>> parent;
        unordered_set<string> cur, next, visited;
        cur.insert(beginWord);
        bool found = false;
        while (!cur.empty() && !found) {
            for (const auto& word : cur) visited.insert(word);
            for (const auto& word : cur) {
                string temp = word;
                for (int i = 0; i < temp.size(); ++i) {
                    char ch = temp[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        temp[i] = c;
                        if (dict.count(temp) && !visited.count(temp)) {
                            next.insert(temp);
                            parent[temp].push_back(word);
                            if (temp == endWord) found = true;
                        }
                    }
                    temp[i] = ch;
                }
            }
            cur.swap(next);
            next.clear();
        }

        vector<vector<string>> res;
        if (!found) return res;
        vector<string> path{endWord};
        dfs(endWord, beginWord, parent, path, res);
        return res;
    }
};