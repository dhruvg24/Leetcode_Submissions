class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        // basic approach
        int i=0, j=0, n = nums.size();
        int maxLen = 0;
        long long prod = 1;
        while(j<n){
            prod*=nums[j];
            if(prod>0){
                prod = 1;
                // to avoid overflow
                maxLen = max(maxLen, j -i + 1);
            }
            else if(prod == 0){
                i = j + 1;
                prod = 1;
            }
            else{
                prod = -1;
            }
            j++;
        }
        // now check from last
        reverse(nums.begin(), nums.end());
        i = 0, j = 0, prod = 1;
        int maxLenRev = 0;
        while(j<n){
            prod*=nums[j];
            if(prod>0){
                maxLenRev = max(maxLenRev, j -i + 1);
                prod = 1;
                // to avoid overflow of prod
            }
            else if(prod == 0){
                i = j + 1;
                prod = 1;
            }
            else{
                prod = -1;
            }
            j++;
        }
        maxLen = max(maxLen, maxLenRev);
        return maxLen;

    }
};
