class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       priority_queue<int> pq(nums.begin(), nums.end());
        while(k>=2){
           pq.pop();
           k--;
        }
        return pq.top();
    }
};

// for kth largest remove k - 1 top elements


