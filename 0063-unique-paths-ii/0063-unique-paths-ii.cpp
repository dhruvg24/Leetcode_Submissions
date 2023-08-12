class Solution {
public:
    int solve(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(r>=0 && c>=0 && grid[r][c]==1){
            return 0;
        }
        if(r==0 && c==0){
            return 1;
        }
        if(r<0 || c<0)
            return 0;
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int goUp = solve(r-1, c, grid, dp);
        int goLeft = solve(r, c-1, grid, dp);
        return dp[r][c] = goUp+goLeft;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>>dp(m, vector<int> (n, -1));
        return solve(m-1, n-1, obstacleGrid, dp);

    }
};