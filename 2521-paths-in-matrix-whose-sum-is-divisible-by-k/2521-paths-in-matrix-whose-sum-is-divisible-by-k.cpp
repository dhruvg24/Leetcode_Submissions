class Solution {
public:
    int n, m, mod = 1e9+7;
    int solve(int r, int c, int curSum , vector<vector<int>> &grid, int k, vector<vector<vector<int>>> &dp){
        if(r<0 || r>=n || c<0 || c>=m)
            return 0;
        if(dp[r][c][curSum]!=-1){
            return dp[r][c][curSum];
        }
        if(r == n - 1  && c == m - 1){
            if((curSum + grid[r][c])%k==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        int ways = 0;
        ways=(ways + solve(r + 1, c, (curSum + grid[r][c])%k,grid, k, dp)%mod)%mod;
        ways=(ways + solve(r , c+1, (curSum + grid[r][c])%k,grid, k, dp)%mod)%mod;
        return dp[r][c][curSum] = ways%mod;

    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        // states r, c, sum
        n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (m + 1, vector<int> (k + 1, -1)));
        return solve(0, 0, 0, grid, k, dp);
    }
};
