class Solution {
    public:
    int findIdx(int idx, int lastIdx, vector<vector<int>> &offers){
        int n= offers.size();
        int l = idx, r = n-1, ans = -1;
        while(l<=r){
            int mid = (l+r)/2;
            int start = offers[mid][0];
            if(start>lastIdx){
                r = mid - 1;
                ans = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
    int solve(int idx, int m, vector<int> &dp, vector<vector<int>> &offers){
        int ans=0;
        if(idx==m){
            return 0;
        }
        if(dp[idx]!=-1)
            return dp[idx];
        // not pick
        int maxProfit = solve(1 + idx, m, dp, offers);
        // pick
        // need to get the next index for which the houses can be sold
        int nextIdx=findIdx(1+idx, offers[idx][1],offers);
        // we will start searching from next index
        if(nextIdx!=-1)
            maxProfit = max(maxProfit, offers[idx][2] + solve(nextIdx, m, dp, offers));
        else
            maxProfit = max(maxProfit, offers[idx][2]);

        return dp[idx] = maxProfit;
    }

    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        int m = offers.size();
        sort(offers.begin(), offers.end());
        vector<int> dp(m, -1);
        return solve(0, m,dp,offers);
    }
};


