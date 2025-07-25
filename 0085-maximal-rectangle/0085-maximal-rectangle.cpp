class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(),  m = matrix[0].size();
        vector<vector<int>> v(n,vector<int>(m,0));

        for(int i=0; i<n ;i++){
            for(int j=0; j<m; j++){
                if(i == 0){
                    v[i][j] = matrix[i][j] - '0';
                }
                else{
                    v[i][j] = (matrix[i][j] == '1') ? v[i-1][j] + 1 : 0;
                }
            }
        }

        int area = INT_MIN;
        for(int i=0; i<n; i++){
            area = max(area, largestRect(v[i]));
        }
        return area;
    }
    
    int largestRect(vector<int>& heights) {
        int n = heights.size();
        vector<int> next(n), prev(n);
        next = nextSmallest(heights, n);
        prev = prevSmallest(heights, n);

        int area = INT_MIN;
        for(int i=0; i<n; i++){
            int l = heights[i];
            if(next[i] == -1){
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int currArea = l * b;
            area = max(area, currArea);
        }

        return area;
    }

    vector<int> nextSmallest(vector<int>& arr, int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=n-1; i>=0; i--){
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }

        return ans;
    }

    vector<int> prevSmallest(vector<int>& arr, int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=0; i<n; i++){
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }

        return ans;
    }
};