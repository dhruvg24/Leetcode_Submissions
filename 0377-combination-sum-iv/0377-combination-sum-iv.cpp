class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target+1);
        dp[0]=1;
        int n = nums.size();
        for(int sum = 1;sum<=target;sum++){
            for(int idx = 0;idx<n;idx++){
                if(nums[idx]<=sum){
                    dp[sum]+=dp[sum-nums[idx]];
                }
            }
        }
        return dp[target];
    }
};