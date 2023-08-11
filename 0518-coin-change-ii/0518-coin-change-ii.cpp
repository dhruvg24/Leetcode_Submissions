class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        for(int i = 0;i<=n;i++){
            // for amt = 0 all wd be marked as 1
            dp[i][0] = 1;
        }
        for(int i = 1;i<=n;i++){
            // traversing the indexes
            for(int j = 1;j<=amount;j++){
                // for every possible amount which is left 
                int take = 0;
                if(j>=coins[i - 1]){
                    take = dp[i][j - coins[i-1]];
                }
                int nottake = dp[i-1][j];

                dp[i][j] = take+nottake;
            }
        }
        return dp[n][amount];
    }
};
