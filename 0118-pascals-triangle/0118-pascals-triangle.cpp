class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res;

        for(int i=0; i<n; i++){
            vector<int> v;

            for(int j=0; j<=i; j++){
                int num;
                if(j == 0 || i == j){
                    num = 1;
                }
                else{
                    num = res[i-1][j-1] + res[i-1][j];
                }
                v.push_back(num);
            }

            res.push_back(v);
        }

        return res;
    }
};