class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        auto solve = [&](string op){
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();

            if(op == "+") return a+b;
            else if(op == "-") return a-b;
            else if(op == "*") return a*b;
            else if(op == "/") return a/b;
            
            return -1;
        };

        for(string c : tokens){
            if(c == "+" || c == "-" || c == "*" || c =="/") st.push(solve(c));
            else st.push(stoi(c));
        }

        return st.top();
    }
};