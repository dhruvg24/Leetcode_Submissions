class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        vector<vector<int>>dist(n, vector<int> (m, 1e9));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while(!pq.empty()){
            auto it = pq.top();
            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;
            pq.pop();

            if(r == n - 1 && c == m- 1){
                return diff;
            }
            for(int i =0;i<4;i++){
                int newr = r + dx[i];
                int newc = c + dy[i];

                if(newr>=0 && newc>=0 && newr<n && newc<m){
                    int newEffort = max(abs(heights[r][c] - heights[newr][newc]), diff);

                    if(newEffort<dist[newr][newc]){
                     dist[newr][newc] = newEffort;
                     pq.push({newEffort, {newr, newc}});

                    }
                }
            }
        }

        return 0;
    }
};