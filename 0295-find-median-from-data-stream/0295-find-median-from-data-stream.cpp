class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> max;
    priority_queue<int> min;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(max.size() == 0 || max.top() < num){
            max.push(num);
        }
        else{
            min.push(num);
        }

        if(max.size() > min.size()+1){
            min.push(max.top());
            max.pop();
        }
        else if(min.size() > max.size()+1){
            max.push(min.top());
            min.pop();
        }
    }
    
    double findMedian() {
        if(max.size() == 0) return 0;

        if(max.size() == min.size()){
            return (max.top() + min.top())/2.0;
        }
        else{
            return max.size() > min.size() ? max.top() : min.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */