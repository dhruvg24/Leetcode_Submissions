class Solution {
public:
    int solve(int l, int r, int maxStreak, vector<int> &boxes, vector<vector<vector<int>>> &dp){
        if(l>r)
            return 0;
        if(dp[l][r][maxStreak]!=-1)
            return dp[l][r][maxStreak];
        int score = solve(l+1,r,0,boxes, dp) + (maxStreak+1)*(maxStreak+1);
        for(int idx= l+1;idx<=r;idx++){
            if(boxes[l]==boxes[idx]){
                // considering a streak or start a new one
                score = max({score, solve(l+1, idx-1, 0, boxes, dp)+solve(idx, r, 1+ maxStreak, boxes, dp)});
            }
        }
        return dp[l][r][maxStreak]=score;
    }
    int removeBoxes(vector<int>& boxes) {
        // dp(memoize)
        int n = boxes.size();
        vector<vector<vector<int>>> dp(n , vector<vector<int>>(n, vector<int>(n,-1)));
        // l , r , maxStreak -> states
        return solve(0,n-1,0,boxes,dp);
    }
};