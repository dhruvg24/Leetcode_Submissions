class Solution {
public:
    int n, m;
    void DFS(vector<vector<int>> &image, int r, int c, int col ,int newCol){
        if(r<0 || r>=n || c<0 || c>=m || image[r][c]==newCol || image[r][c]!=col){
            return;
        }
        image[r][c] =newCol;
        DFS(image, r + 1, c, col, newCol), DFS(image, r-1, c, col, newCol), DFS(image, r, c+1, col, newCol), DFS(image, r, c-1, col, newCol);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size(), m = image[0].size();
        int val = image[sr][sc];
        DFS(image, sr, sc, val, color);
        return image;        
    }
};