class Solution {
public:
    int mod = 1e9+7;
    int numMusicPlaylists(int n, int goal, int k) {
        // constraint-> all possibilities listing not possible
        // dp[i][j]-> list of songs having length i and having j unique songs
        // dp[goal][n] - playlist len goal, n unique songs

        // dp[0][0]=1 -> empty playlist
        // for i<j : dp[i][j]=0
        // for playlist with i-1 songs and j - 1 unique songs -> adding 1 => (i,j)
        //     num of new songs left = n-(j-1)
        //     so num playlist = dp[i-1][j-1].(n-j+1)

        // if replay song len+=1, numUnique remains same j
        //     if j>k-> replay j-k songs -> choices -> dp[i-1][j].(j-k) -> playlists
        vector<vector<long long>> dp(goal+1, vector<long long>(n+1, 0));
        dp[0][0]=1;
        for(int i=1;i<=goal;i++){
            for(int j= 1;j<=min(i, n);j++){
                dp[i][j] = dp[i-1][j-1]*(n-j+1)%mod;
                if(j-k>0){
                    dp[i][j]=(dp[i][j]+dp[i-1][j]*(j-k))%mod;
                }
            }
        }

        return dp[goal][n];

    }
};