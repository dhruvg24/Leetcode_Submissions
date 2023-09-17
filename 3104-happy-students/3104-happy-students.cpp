class Solution {
public:
    int countWays(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int cnt=0;
        // if no student selecteed
        if(nums[0]>0){
            cnt++;
        }
        for(int i = 0;i<n-1;i++){
            if(nums[i]<i+1 && 1+i<nums[i+1]){
                // 2nd condition for not selected student
                
                cnt++;
            }
        }
        if(nums[n-1]<n){
            // if all are selected 
            cnt++;
        }
        return cnt;
    }
};