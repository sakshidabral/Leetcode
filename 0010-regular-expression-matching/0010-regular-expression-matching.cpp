class Solution {
public:
    bool isMatch(string s, string p) {
        return solve(0 ,0, s, p);
    }

    bool solve(int i, int j, string& s, string& p){
        if(j == p.size()){
            return i == s.size();
        }
        
        bool first_char_matched = false;

        if(i < s.size() && (p[j] == s[i] || p[j] == '.')){
            first_char_matched = true;
        }

        if(p[j+1] == '*'){
            bool skip = solve(i, j+2, s, p);
            bool take = first_char_matched && solve(i+1, j, s, p);
            return skip || take;
        }
        
        return first_char_matched && solve(i+1, j+1, s, p);
    }
};