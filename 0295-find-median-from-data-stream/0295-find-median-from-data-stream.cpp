class MedianFinder {
public:
// maintain a min heap and max heap
    priority_queue<int> pq;
    priority_queue<int, vector<int> , greater<int>>pq1;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        pq.push(num);
        pq1.push(pq.top());
        pq.pop();
        if(pq1.size()>pq.size()){
            pq.push(pq1.top());
            pq1.pop();
        }

    }
    
    double findMedian() {
        if(pq.size() == pq1.size()){
            return double((pq.top() + pq1.top())/2.0);
        }
        else{
            if(pq.size()>pq1.size())
                return double(pq.top());
            else
                return double(pq1.top());
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
