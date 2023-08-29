class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    void DFS(int r, int c, vector<vector<char>> &board, vector<vector<bool>> &vis){
        int n = board.size(), m = board[0].size();
        vis[r][c] = true;
        for(int del = 0;del<4;del++){
            int newr = r + dx[del], newc = c + dy[del];
            if(newr>=0 && newr<n && newc>=0 && newc<m && board[newr][newc]=='O' && vis[newr][newc] == false){
                DFS(newr, newc, board, vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(board[i][j]=='O' && (i == 0 || j == 0 || i == n - 1 || j == m - 1)){
                    DFS(i, j, board, vis);
                }
            }
        }

        // for all not vis O flip them
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j] && board[i][j] =='O'){
                    board[i][j] = 'X';
                }
            }
        }

    }
};
