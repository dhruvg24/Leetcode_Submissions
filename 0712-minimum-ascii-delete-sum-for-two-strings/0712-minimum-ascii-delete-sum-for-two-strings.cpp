class Solution {
public:
    vector<vector<int>> dp;
    int solve(string &s1, string &s2, int i, int j){
        if(dp[i+1][j+1]!=-1)
            return dp[i+1][j+1];
        // base cases
        if(i<0){
            int cost = 0;
            for(int k = 0;k<=j;k++){
                cost += s2[k];
            }
            return dp[i+1][j+1]=cost;
        }

        if(j<0){
            int cost = 0;
            for(int k = 0;k<=i;k++){
                cost+=s1[k];
            }
            return dp[i+1][j+1]=cost;
        }
        // 3 cases delete ith char from s1 and solve remaining
        // delete jth char from s2 and solve remaining
        // delete both char from s1 and s2 and solve remaining 
        if(s1[i]==s2[j])
            return dp[i+1][j+1]=solve(s1, s2, i-1,j-1); //NO COST
        
        return dp[i+1][j+1]=min(s1[i] + solve(s1, s2, i-1, j), s2[j] + solve(s1, s2, i, j-1));
        
    }
    int minimumDeleteSum(string s1, string s2) {
        // deletion can be performed on any char .... not necessarily consecutive chars
        // order of char cant be ignored
        // need to make common subsequence only
        int m = s1.size(), n = s2.size();
        dp.assign(m+1, vector<int> (n+1,-1));
        return solve(s1,s2,m - 1, n - 1);
    }
};