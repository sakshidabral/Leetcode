class Solution {
public:
    bool isMatch(string s, string p) {
        int l1 =s.size(), l2 = p.size();
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, -1));

        return solve(s, p, dp);
    }

    bool solve(string s, string p, vector<vector<int>> &dp){
        if(p.size() == 0){
            return s.size() == 0;
        }
        
        bool first_char_matched = false;

        if(s.size() > 0 && (p[0] == s[0] || p[0] == '.')){
            first_char_matched = true;
        }

        if(p.size() >=2 && p[1] == '*'){
            bool skip = solve(s, p.substr(2), dp);
            bool take = first_char_matched && solve(s.substr(1), p, dp);
            return skip || take;
        }
        
        return first_char_matched && solve(s.substr(1), p.substr(1), dp);
    }
};