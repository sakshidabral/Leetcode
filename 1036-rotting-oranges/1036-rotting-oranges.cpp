class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int fresh = 0;
        queue<pair<int,int>> q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        int time = 0;
        vector<pair<int,int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        while(!q.empty()){
            bool rotted = false;
            int size = q.size();

            for(int i=0; i<size; i++){
                auto [x,y] = q.front();
                q.pop();

                for(auto [dx, dy] : dir){
                    int newx = x + dx;
                    int newy = y + dy;

                    if(newx >= 0 && newx < m && newy >= 0 && newy < n && grid[newx][newy] == 1){
                        grid[newx][newy] = 2;
                        fresh--;
                        q.push({newx, newy});
                        rotted = true;
                    }
                }
            }

            if(rotted == true){
                time++;
            }
        }

        return fresh == 0 ? time : -1;
    }

};