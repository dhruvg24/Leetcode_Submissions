class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int minMoves = INT_MAX;
        for(int i=0;i<3;i++){
            for(int j =0;j<3;j++){
                if(grid[i][j]==0){
                    for(int p = 0;p<3;p++){
                        for(int q = 0;q<3;q++){
                            if(grid[p][q]>1){
                                grid[i][j]++, grid[p][q]--;
                                int dis = abs(i-p)+abs(j-q);
                                minMoves = min(minMoves, dis+minimumMoves(grid));
                                grid[p][q]++, grid[i][j]--;
                            }
                        }
                    }
                }
            }
        }
        if(minMoves==INT_MAX){
            return 0;
        }
        return minMoves;
        
    }
};