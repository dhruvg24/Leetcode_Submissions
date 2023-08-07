class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //binary search
        int n = matrix.size(), m = matrix[0].size();
        int l = 0, h = n*m - 1;
        while(l<=h){
            int mid = l + (h - l)/2;
            int c = mid%m, r = mid/m;
            if(matrix[r][c] == target){
                return true;
            }
            else if(matrix[r][c]>target){
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return false;
    }

};