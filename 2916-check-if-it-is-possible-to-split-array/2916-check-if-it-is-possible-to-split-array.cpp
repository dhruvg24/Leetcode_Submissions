class Solution {
public:
    bool isValid(vector<int>& nums, int m , int l, int r){
        int sum=0;
        for(int i=l;i<=r;i++)
            sum+=nums[i];
        return sum>=m;
    }
    bool solve(vector<int> &nums, vector<vector<int>> &dp, int m, int l, int r){
        if(l==r)
            return true;
        if(!isValid(nums, m, l , r))
            return false;
        if(dp[l][r]!=-1)
            return dp[l][r]==1;
        // only if subarr [l, r]=> valid then break
        bool ans=false;
        for(int cut=l;cut<r;cut++){
            bool leftPart = solve(nums, dp, m, l, cut);
            bool rightPart = solve(nums, dp, m, cut+1,r);
            if(leftPart == true && rightPart == true){
                ans = true;
                break;
            }

        }
        return dp[l][r]=ans;
    }
    bool canSplitArray(vector<int>& nums, int m) {
        // partition dp
        int n= nums.size();;
        if(n<=2)
            return true;
        vector<vector<int>> dp(n, vector<int> (n,-1));
        return solve(nums, dp, m,0, n-1);
    }
};