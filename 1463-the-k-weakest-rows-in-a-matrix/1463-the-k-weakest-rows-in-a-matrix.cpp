class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> pq;
        int n = mat.size(), m = mat[0].size();
        for(int i = 0;i<n;i++){
            int cnt=0;
            for(int j = 0;j<m;j++){
                if(mat[i][j]==1){
                    cnt++;
                }

            }
            pq.push({cnt, i});
        }

        vector<int> res;
        while(k--){
            int tmp = pq.top().second;
            pq.pop();
            res.push_back(tmp);
        }
        return res;
    }
};