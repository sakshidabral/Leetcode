class Solution {
public:
    bool isMatch(string s, string p) {
        return solve(s, p);
    }

    bool solve(string s, string p){
        if(p.size() == 0){
            return s.size() == 0;
        }
        
        bool first_char_matched = false;

        if(s.size() > 0 && (p[0] == s[0] || p[0] == '.')){
            first_char_matched = true;
        }

        if(p.size() >=2 && p[1] == '*'){
            bool skip = solve(s, p.substr(2));
            bool take = first_char_matched && solve(s.substr(1), p);
            return skip || take;
        }
        
        return first_char_matched && solve(s.substr(1), p.substr(1));
    }
};