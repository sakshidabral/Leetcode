class Solution {
public:
    int maximum69Number (int num) {
        bool changed = false;
        string n = to_string(num);

        for(int i=0; i<n.size(); i++){
            if(n[i] == '6'){
                n[i] = '9';
                break;
            }
        }

        num = stoi(n);
        return num;
    }
};