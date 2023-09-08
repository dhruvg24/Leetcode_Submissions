class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for(int i = 0;i<numRows;i++){
            // column gets increased by 1 each time
            ans[i].resize(i + 1);
            ans[i][0] = ans[i][i] = 1;
            // first and last col marked
            for(int j = 1;j<=i-1;j++){
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
        }
        return ans;
    }
};