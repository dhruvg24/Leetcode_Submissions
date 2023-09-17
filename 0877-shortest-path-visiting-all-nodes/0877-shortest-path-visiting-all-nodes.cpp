class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        // 1. need to get shortest path by starting with every possible node
        // 2. Basic BFS -> wont work (vis array may repeat the nodes visited), i.e. in this case node can be visited again and again

        // 3.There can be indefinite loop bcoz for eg. 1 0 1 0 1 0 ... 

        // here we keep track of [current number on which we are at , curr state of bit number] -> bit number represents the value 1-> if visited , 0 -> if not visited
        
        // base case
        int n = graph.size();
        if(n == 1){
            return 0;
        }
        // the final state will be when bit number is 11111...1 for all the nodes
        // that is 2^n - 1 will be the decimal value
        int finalState = (1<<n) - 1;
        // 2^graph.size - 1

        queue<pair<int,int>> q;
        // now to start with node i the ith bit has to be set and all others will be 0 at that starting point
        for(int i = 0;i<n;i++){
            q.push({i, 1<<i});
            // eg. for node 0 -> {0, 100} if there are 3 nodes
        }
        // now need to keep track of number, bit state
        int shortestPath = 0;
        vector<vector<bool>> vis(n, vector<bool>(finalState, false));

        // Standard BFS
        while(!q.empty()){
            shortestPath++;
            int qsize = q.size();
            while(qsize--){
                auto &it = q.front();
                int currNode = it.first, currVisState = it.second;
                q.pop();
                for(auto &adjNode:graph[currNode]){
                    // we skip the node if we already have same visState present
                    // this is to avoid indefinite loop
                    int nextState = (currVisState | (1<<adjNode));
                    // eg. {0, 011} -> 2 ways either {1, 011}  OR {2, 111} , since {1, 011} already -> reject, and go to the other way, as soon as all bits get set -> return the shortestPath value
                    if(nextState == finalState){
                        return shortestPath;
                    }
                    if(!vis[adjNode][nextState]){
                        vis[adjNode][nextState] = true;
                        q.push({adjNode, nextState});
                    }
                }
            }
        }
        
        return -1;
    }
};