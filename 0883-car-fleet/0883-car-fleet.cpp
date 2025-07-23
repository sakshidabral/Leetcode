class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        int n = position.size();

        for(int i=0;i<n;i++){
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end());
        stack<float> st;
        int c = cars.size();

        for(int i=0; i<c; i++){
            float time = (target - cars[i].first) / (float)cars[i].second;
            if(st.empty()) st.push(time);
            else{
                while(!st.empty() && time >= st.top()){
                    st.pop();
                }
                st.push(time);
            }
        }

        return st.size();
    }
};