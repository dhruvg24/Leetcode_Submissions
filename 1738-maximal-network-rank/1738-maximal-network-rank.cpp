class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int maxi=0;
        unordered_map<int, unordered_set<int>> adj;
        // {city, adj city}

        for(auto it: roads){
            adj[it[0]].insert(it[1]), adj[it[1]].insert(it[0]);

        }
        for(int i=0;i<n;i++){
            for(int j = i + 1;j<n;j++){
                // for all pairs
                int curCnt = adj[i].size() + adj[j].size();
                if(adj[i].find(j)!=adj[i].end()){
                    // if not in direct connection remove the count
                    --curCnt;
                }
                maxi = max(maxi, curCnt);
            }
        }
        return maxi;
    }
};