class Solution {
public:
    int leastInterval(vector<char>& tasks, int p) {
        int n = tasks.size();
        unordered_map<char,int> m;
        for(char c : tasks){
            m[c]++;
        }

        priority_queue<int> pq;
        for(auto i : m){
            pq.push(i.second);
        }

        int time = 0;

        while(!pq.empty()){
            vector<int> temp;
            for(int i=1; i<=p+1; i++){
                if(!pq.empty()){
                    temp.push_back(pq.top()-1);
                    pq.pop();
                }
            }

            for(int rem : temp){
                if(rem > 0){
                    pq.push(rem);
                }
            }

            if(!pq.empty()){
                time += p+1;
            }
            else{
                time += temp.size();
            }
        }

        return time;
    }
};