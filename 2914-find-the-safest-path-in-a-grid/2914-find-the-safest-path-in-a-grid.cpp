class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    bool BFS(vector<vector<int>> &dist, int safeDist){
        int n = dist.size();
        if(dist[0][0]<safeDist)
            return false;
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool> (n, false));
        vis[0][0]=true;
        q.push({0, 0});
        while(!q.empty()){
            int qsize = q.size();
            while(qsize--){
                auto it = q.front();
                int r = it.first, c = it.second;
                q.pop();
                if(r==n-1 && c==n-1)
                    return true;
                for(int del = 0;del<4;del++){
                    int newr = r + dx[del], newc = c + dy[del];
                    if(newr>=0 && newr<n && newc>=0 && newc<n && dist[newr][newc]>=safeDist && !vis[newr][newc]){
                        q.push({newr, newc});
                        vis[newr][newc]=true;

                    }
                }
            }
        }
        return false;

        
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        // n x n
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool> (n, false));
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==1)
                {
                    // thief 
                    dist[i][j]=0;
                    vis[i][j]=true;
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()){
            int qsize = q.size();
            while(qsize--){
                int r = q.front().first, c = q.front().second;
                q.pop();
                for(int del = 0;del<4;del++){
                    int newr = r + dx[del], newc = c + dy[del];
                    if(newr>=0 && newr<n && newc>=0 && newc<n && !vis[newr][newc]){
                        vis[newr][newc]=true;
                        q.push({newr, newc});
                        dist[newr][newc] = 1 + dist[r][c];
                    }
                }
            }
        }

        // apply bin search to maximise the safeness factor
        int l = 0, r = 1e9, ans = 0;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(BFS(dist, mid))
            {
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid - 1;
            }
        }
        return ans;
    }
};