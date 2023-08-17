class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        vector<vector<int>> dist(m, vector<int>(n,1e5));
        queue<pair<pair<int, int>,int> >q;
        // r, c, dist store
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(mat[i][j] == 0){
                    q.push({{i, j}, 0});
                    dist[i][j] = 0;
                    // dist from 0 is 0
                }
            }
        }
        // q contains all 0s
        while(!q.empty()){
            auto tmp = q.front();
            int r = tmp.first.first, c = tmp.first.second, d = tmp.second;
            q.pop();
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            for(int i = 0;i<4;i++){
                int newr = r + dx[i];
                int newc = c + dy[i];
                if(newr>=0 && newr<m && newc>=0 && newc<n){
                    if(mat[newr][newc] == 1 && dist[newr][newc]>d + 1){
                        dist[newr][newc] = min(dist[newr][newc], d + 1);
                        q.push({{newr, newc}, d + 1});
                    }

                }
            }
        }
        return dist;
    }
};

