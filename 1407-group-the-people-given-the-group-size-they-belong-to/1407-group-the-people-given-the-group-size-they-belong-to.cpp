class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> mp;
        // here we store the ith value and corresponding indexes at which it lies
        int n = groupSizes.size();
        for(int i = 0;i<n;i++){
            mp[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for(auto it: mp){
            int val = it.first;
            vector<int> res;
            for(auto x: it.second){
                res.push_back(x);
                if(val == res.size())
                {
                    // need to make group size = it.first
                    ans.push_back(res);
                    res = {};
                    // reset res to empty
                }
            }
        }
        return ans;
    }
};