class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        // in non decreasing order
        // go from R -> L
        // the curr index element is the max one, if its greater than prev then it is fine otherwise need to break it
        // eg. 5 6 7 8 1 2 3
        // if l->r need to keep on breaking initial elements to adjust -> N^2
        // r->l break st <= elem on right

        int n = nums.size(), nextEle = 1e9+7;
        long long minReplace = 0;
        for(int i = n - 1;i>=0 ;i--){
            if(nums[i]<=nextEle){
                // good to go
                nextEle = nums[i];
                continue;
            }
            long long numParts = ceil(nums[i]/(double)nextEle);
            minReplace += numParts - 1;
            nextEle = nums[i]/numParts;

        }
        return minReplace;
    }
};