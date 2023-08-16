class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // using pq
        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        // {nums[idx], idx}

        vector<int> ans;
        for(int i =0;i<k-1;i++){
            pq.push({nums[i], i});
            // for initial k elements
        }
        for(int i=k-1;i<n;i++){
            while(!pq.empty() && pq.top().second < i - k + 1)
            // max element in curr pq should not be out of range
            // so all such elem are popped out
                pq.pop();
            pq.push({nums[i], i});
            ans.push_back(pq.top().first);
            // each time max element
        }
        return ans;

    }
};


