class Solution {
private:
    
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0) return ans;

        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl","mno","pqrs","tuv","wxyz"};

        solve(digits, "", 0, ans, mapping);
        return ans;
    }

    void solve(string digit, string output, int i, vector<string>& ans, string mapping[] ) {
        
        //base case
        if(i >= digit.length()) {
            ans.push_back(output);
            return;
        }
        
        int num = digit[i] - '0';
        string value = mapping[num];
        
        for(int j=0; j<value.length(); j++) {
            output.push_back(value[j]);
            solve(digit, output, i+1, ans, mapping);
            output.pop_back();
        }
        
    }
};