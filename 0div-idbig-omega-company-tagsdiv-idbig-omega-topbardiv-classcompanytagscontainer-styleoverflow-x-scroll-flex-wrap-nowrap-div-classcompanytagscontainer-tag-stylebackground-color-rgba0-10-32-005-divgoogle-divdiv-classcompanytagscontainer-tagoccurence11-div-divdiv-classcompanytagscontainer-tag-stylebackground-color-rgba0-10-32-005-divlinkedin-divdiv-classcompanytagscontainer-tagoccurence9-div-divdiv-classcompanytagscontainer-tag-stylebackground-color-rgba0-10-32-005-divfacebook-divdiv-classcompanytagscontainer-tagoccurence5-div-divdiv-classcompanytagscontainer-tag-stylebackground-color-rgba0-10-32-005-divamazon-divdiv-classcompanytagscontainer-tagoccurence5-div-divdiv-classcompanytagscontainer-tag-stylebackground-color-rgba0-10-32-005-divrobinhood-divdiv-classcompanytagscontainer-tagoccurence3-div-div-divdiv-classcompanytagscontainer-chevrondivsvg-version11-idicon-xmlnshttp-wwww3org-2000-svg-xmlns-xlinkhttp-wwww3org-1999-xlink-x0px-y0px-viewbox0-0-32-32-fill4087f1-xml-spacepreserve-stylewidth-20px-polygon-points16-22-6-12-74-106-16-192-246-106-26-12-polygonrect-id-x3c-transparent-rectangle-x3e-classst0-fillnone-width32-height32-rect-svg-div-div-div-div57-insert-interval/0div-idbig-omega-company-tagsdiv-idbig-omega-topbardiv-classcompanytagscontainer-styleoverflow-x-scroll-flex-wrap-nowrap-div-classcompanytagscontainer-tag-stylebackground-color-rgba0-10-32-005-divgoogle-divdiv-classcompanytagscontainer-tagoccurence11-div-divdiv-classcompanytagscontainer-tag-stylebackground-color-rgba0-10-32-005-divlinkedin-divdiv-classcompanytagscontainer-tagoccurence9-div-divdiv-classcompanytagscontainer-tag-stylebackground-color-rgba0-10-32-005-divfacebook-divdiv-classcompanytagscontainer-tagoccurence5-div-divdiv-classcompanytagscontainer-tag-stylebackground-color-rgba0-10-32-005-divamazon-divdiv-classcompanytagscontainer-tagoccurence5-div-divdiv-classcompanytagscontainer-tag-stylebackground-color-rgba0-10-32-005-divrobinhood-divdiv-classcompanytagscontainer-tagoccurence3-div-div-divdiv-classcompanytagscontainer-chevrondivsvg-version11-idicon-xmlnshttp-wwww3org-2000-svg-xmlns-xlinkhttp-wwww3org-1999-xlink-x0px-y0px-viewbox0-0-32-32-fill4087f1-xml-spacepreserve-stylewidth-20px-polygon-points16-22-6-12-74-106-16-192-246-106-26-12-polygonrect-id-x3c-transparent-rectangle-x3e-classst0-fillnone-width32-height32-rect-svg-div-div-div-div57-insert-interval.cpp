class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
//         no overlapping before merge
        int i=0, n = intervals.size();
        while(i<n && newInterval[0]>intervals[i][1]){
            ans.push_back(intervals[i]);
            i++;
        }
        
// overlap handle
        while(i<n && newInterval[1]>=intervals[i][0]){
            newInterval[0]=min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);
//         now for remaining ones just add it to answer
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
        
        
    }
};

