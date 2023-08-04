class Solution {
public:
    int n;
    vector<int> dp;
    bool DFS(int idx, string s, vector<string> &wordDict){
        if(idx == n)
            return true;
        if(dp[idx]!=-1)
            return dp[idx];
        bool res = false;
        for(string word: wordDict){
            int j = word.size();
            if(idx + j>n)
                continue;
            string strWord = s.substr(idx, j);
            if(strWord == word){
                res = res + DFS(idx+j,s, wordDict);
            }
            dp[idx]=res;
            if(res)
                return res;
        }
        return res;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        dp=vector<int> (n,-1);
        return DFS(0, s, wordDict);
    }
};
