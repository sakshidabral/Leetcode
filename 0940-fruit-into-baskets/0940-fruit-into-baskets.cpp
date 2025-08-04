class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int> m;
        int maxx = 0, l = 0;

        for(int r=0; r<n; r++){
            m[fruits[r]]++;

            while(m.size() > 2){
                m[fruits[l]]--;
                if(m[fruits[l]] == 0){
                    m.erase(fruits[l]);
                }
                l++;
            }

            maxx = max(maxx, r-l+1);
        }

        return maxx;
    }
};