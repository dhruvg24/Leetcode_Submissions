class Solution {
public:
// it returns the min of cur value and sum of min in all of its paths
    long long DFS(int idx, vector<vector<int>> &adj,vector<int> &val, vector<bool> &vis){
        vis[idx]= true;
        long long cur = 0;
        bool chk = false;
        for(auto it: adj[idx]){
            if(!vis[it]){
                chk = true;
                cur+=(long long)DFS(it, adj, val, vis);
            }
        }
        if(chk){
            return min(cur, (long long)val[idx]);
        }
        return val[idx];
    }
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = edges.size()+1;
        vector<vector<int>> adj(n);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> vis(n , false);
        long long sm = 0;
        for(int i = 0;i<values.size();i++){
            sm+=values[i];
        }

        for(int i =0;i<n;i++){
            vis[i] = false;
        }
        long long mini = DFS(0, adj, values, vis);
        return sm - mini;
    }
};