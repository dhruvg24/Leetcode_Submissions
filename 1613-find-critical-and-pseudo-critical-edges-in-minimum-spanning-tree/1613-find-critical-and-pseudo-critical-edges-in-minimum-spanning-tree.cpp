class Solution {
public:
    class UnionFind{
        // DSU
        public:
            vector<int> par;
            vector<int> size;
            int maxSize;
            UnionFind(int n){
                par.resize(n);
                size.resize(n, 1);
                maxSize = 1;
                for(int i = 0;i<n;i++){
                    par[i] = i;
                }
            }
            int findUPar(int x){
                //ultimate parent
                if(x!=par[x]){
                    par[x] = findUPar(par[x]);
                }
                return par[x];
            }

            bool merge(int x, int y){
                // merging x and y
                int uParx = findUPar(x), uPary = findUPar(y);
                if(uParx!=uPary){
                    if(size[uParx]<size[uPary]){
                        swap(uParx, uPary);
                    }
                    par[uPary] = uParx;
                    size[uParx] += size[uPary];
                    maxSize = max(maxSize, size[uParx]);
                    return true;
                }
                return false;
            }
    };

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        // if on adding edge total wt of mst inc. - critical
        // if on adding edge total remains same - pseudo critical
        int m = edges.size();
        auto newEdges = edges;
        // will add the index
        for(int i=0;i<m;i++){
            newEdges[i].push_back(i);
        }
        sort(newEdges.begin(), newEdges.end(), [](auto &x, auto &y){
            return x[2]<y[2];
        });

        // finding mst by union find
        UnionFind ds(n);
        int wt = 0;
        for(auto it: newEdges){
            if(ds.merge(it[0], it[1])){
                wt+=it[2];
            }
        }
        vector<vector<int>> ans(2);
        // will contain vector of critical and non-critical edges
        for(int i=0;i<m;i++){
            UnionFind noPick(n);
            int noPickWt = 0;
            for(int j=0;j<m;j++){
                if(i!=j && noPick.merge(newEdges[j][0], newEdges[j][1])){
                    noPickWt += newEdges[j][2];
                }
            }

            // if graph is not connected or total wt greater-> edge critical
            if(noPick.maxSize<n || noPickWt>wt){
                ans[0].push_back(newEdges[i][3]);
            }
            else{
                // force this edge in graph and get mst wt.
                UnionFind forced(n);
                forced.merge(newEdges[i][0], newEdges[i][1]);
                int forcedWt = newEdges[i][2];
                for(int j = 0;j<m;j++){
                    if(i!=j && forced.merge(newEdges[j][0], newEdges[j][1])){
                        forcedWt+=newEdges[j][2];
                    }
                }
                if(forcedWt==wt){
                    ans[1].push_back(newEdges[i][3]);
                }
            }
        }
        return ans;
    }
};