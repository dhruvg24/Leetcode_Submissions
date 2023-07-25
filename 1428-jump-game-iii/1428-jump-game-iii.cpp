class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        // BFS approach
        int n = arr.size();
        //need to keep a track for vis
        queue<int> q;
        vector<bool> vis(n, false);
        q.push(start);
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            if(arr[frontNode] == 0){
                return true;
            }
            vis[frontNode] = true;
            int way_1 = frontNode - arr[frontNode], way_2 = frontNode + arr[frontNode];
            if(way_1>=0 && !vis[way_1]){
                q.push(way_1);
            }
            if(way_2<n&&!vis[way_2]){
                q.push(way_2);
            }
        }
        return false;
    }
};


