class Solution {
public:
    int n;
    int solve(int idx, int prevStep, vector<int> &stones, vector<vector<int>> &dp, unordered_map<int, int> &mp){
        if(idx == n-1){
            return 1;
        }
        if(idx>=n){
            return 0;
        }
        int res = false;
        if(dp[idx][prevStep]!=-1){
            return dp[idx][prevStep];
        }
        // int dx[] = {prevStep -1, prevStep, prevStep+1};
        // int i =0;
        for(int nxt = prevStep-1;nxt<=prevStep+1;nxt++){
            if(nxt==0)
                continue;
            else if(nxt>0 && mp.find(stones[idx]+nxt)!=mp.end()){
                res=res || solve(mp[stones[idx]+nxt], nxt, stones, dp, mp);
            }
        }
        return dp[idx][prevStep] = res;
    }
    bool canCross(vector<int>& stones) {
        // clearly need to work out all possibilities
        // states -> curIdx,prevStep
        n = stones.size();
        // need to store the presence of stones at index
        unordered_map<int, int> mp;
        for(int i = 0;i<n;i++){
           mp[stones[i]]=i;
        }
        vector<vector<int>> dp(2005, vector<int> (2005, -1));

        return solve(0, 0, stones, dp, mp);
    }
};