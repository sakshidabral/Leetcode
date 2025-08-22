class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        unordered_set<int> row, col;

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j] == 1){
                    if(row.find(i) == row.end()) row.insert(i);
                    if(col.find(j) == col.end()) col.insert(j);
                }
            }
        }

        int minr = INT_MAX, maxr = INT_MIN;
        for(int ro : row){
            minr = min(minr, ro);
            maxr = max(maxr, ro);
        }

        int minc = INT_MAX, maxc = INT_MIN;
        for(int co : col){
            minc = min(minc, co);
            maxc = max(maxc, co);
        }

        int l = maxr - minr + 1;
        int b = maxc - minc + 1;

        return l * b;
    }
};