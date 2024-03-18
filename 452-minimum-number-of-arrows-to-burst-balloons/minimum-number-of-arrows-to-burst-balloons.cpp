class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end(),[](const vector<int>&a, const vector<int>&b){
            return a[1]<b[1];
        });
        int arrows=1;//assuming atleast 1 is required
        int prev=points[0][1];
        for(int i=1;i<n;i++){
            if(points[i][0]>prev){
                arrows++;
                prev=points[i][1];
            }
        }
        return arrows;
    }
};