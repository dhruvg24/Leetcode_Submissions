class Solution {
public:
    int minExtraChar(string s, vector<string>& dic) {
        // break such that longest substring are formed & should belong to dictionary
        int n = s.size(), minCharLeft = n;
        vector<int> dp(n + 1, n + 1);
        dp[0] = 0;
        unordered_set<string> st(dic.begin(), dic.end());
        for(int idx = 1;idx<=n;idx++){
            dp[idx] = 1 + dp[idx-1];
            for(int l = 1;l<=idx;l++){
                if(st.find(s.substr(idx - l, l))!=st.end()){
                    dp[idx] = min(dp[idx], dp[idx - l]);
                }
            }
        }
        return dp[dp.size()-1];


    }
};