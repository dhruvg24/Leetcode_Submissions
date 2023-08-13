class Solution {
public:
    int n;
    bool solve(int idx, vector<int> &nums, vector<int> &dp){
        if(idx>=n)
            return true;
        if(dp[idx]!=-1)
            return dp[idx];
        bool res=false;
        if(idx+1<=n-1 && nums[idx]==nums[idx+1]){
            res |= solve(idx+2, nums, dp);
        }
        if(idx + 2<=n-1 && nums[idx]==nums[idx+1] && nums[idx+1]==nums[idx+2]){
            res |= solve(idx + 3, nums, dp);
        }
        if(idx + 2<=n-1 && nums[idx+1] == 1 + nums[idx] && nums[idx+2] ==1 + nums[idx+1])
            res|=solve(idx + 3, nums, dp);
        return dp[idx] = res;
    }
    bool validPartition(vector<int>& nums) {
        n = nums.size();
        vector<int>dp(n,-1);
        return solve(0,nums , dp);
    }
};
