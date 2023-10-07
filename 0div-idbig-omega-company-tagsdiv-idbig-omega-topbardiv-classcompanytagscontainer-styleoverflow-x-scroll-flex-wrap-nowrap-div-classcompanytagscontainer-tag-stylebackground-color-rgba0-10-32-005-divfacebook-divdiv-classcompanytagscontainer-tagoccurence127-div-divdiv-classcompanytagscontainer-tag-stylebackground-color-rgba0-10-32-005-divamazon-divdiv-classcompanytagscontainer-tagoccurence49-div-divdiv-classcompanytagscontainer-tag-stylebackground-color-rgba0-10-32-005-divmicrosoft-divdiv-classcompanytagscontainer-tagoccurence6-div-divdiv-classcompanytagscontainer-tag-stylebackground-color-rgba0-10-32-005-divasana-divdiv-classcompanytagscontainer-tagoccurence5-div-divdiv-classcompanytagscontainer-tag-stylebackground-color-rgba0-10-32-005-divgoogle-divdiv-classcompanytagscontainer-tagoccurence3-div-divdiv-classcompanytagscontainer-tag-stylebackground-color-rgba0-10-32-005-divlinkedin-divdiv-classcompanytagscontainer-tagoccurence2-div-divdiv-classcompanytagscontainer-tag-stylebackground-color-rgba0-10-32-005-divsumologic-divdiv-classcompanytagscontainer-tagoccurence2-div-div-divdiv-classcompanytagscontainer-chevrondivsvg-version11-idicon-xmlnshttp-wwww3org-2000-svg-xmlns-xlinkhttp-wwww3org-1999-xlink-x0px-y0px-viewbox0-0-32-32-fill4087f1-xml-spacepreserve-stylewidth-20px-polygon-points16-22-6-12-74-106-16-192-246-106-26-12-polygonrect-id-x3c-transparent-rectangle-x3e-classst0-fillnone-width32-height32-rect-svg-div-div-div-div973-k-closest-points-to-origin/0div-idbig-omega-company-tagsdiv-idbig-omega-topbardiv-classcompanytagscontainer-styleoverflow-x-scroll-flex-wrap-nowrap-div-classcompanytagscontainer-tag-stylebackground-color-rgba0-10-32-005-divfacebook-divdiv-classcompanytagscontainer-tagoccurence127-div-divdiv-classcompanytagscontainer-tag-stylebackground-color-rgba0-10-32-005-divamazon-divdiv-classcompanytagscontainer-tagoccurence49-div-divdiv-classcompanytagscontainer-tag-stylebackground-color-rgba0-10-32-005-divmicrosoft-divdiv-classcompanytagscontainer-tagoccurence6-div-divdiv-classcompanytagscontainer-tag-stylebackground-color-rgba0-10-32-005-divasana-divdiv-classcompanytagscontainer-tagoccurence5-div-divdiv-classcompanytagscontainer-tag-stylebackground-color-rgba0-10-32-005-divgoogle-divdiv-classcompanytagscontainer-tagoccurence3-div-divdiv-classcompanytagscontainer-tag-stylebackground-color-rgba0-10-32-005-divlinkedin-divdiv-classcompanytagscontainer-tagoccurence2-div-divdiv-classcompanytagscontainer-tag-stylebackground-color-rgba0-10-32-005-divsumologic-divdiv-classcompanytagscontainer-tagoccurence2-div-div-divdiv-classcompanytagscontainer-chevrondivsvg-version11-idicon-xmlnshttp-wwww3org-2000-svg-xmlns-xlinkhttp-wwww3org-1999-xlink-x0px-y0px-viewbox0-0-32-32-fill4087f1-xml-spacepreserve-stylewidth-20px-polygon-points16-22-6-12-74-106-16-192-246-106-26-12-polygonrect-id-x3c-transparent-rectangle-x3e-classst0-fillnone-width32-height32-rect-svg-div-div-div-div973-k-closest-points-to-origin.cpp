class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<vector<int>>pq;
        
        for(auto it: points){
            int x = it[0], y= it[1];
            pq.push({x*x + y*y, x, y});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            vector<int> vec = pq.top();
            pq.pop();
            res.push_back({vec[1], vec[2]});
        }
        return res;
    }
};
