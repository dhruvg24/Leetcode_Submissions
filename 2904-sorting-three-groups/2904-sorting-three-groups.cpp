class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        // brute force
        int n = nums.size(), ans = n;
        for(int i = 0;i<=n;i++){
            for(int j = 0;j<=n;j++){
                int cur = 0;
                for(int k = 0;k<n;k++){
                    if(k<i){
                        if(nums[k]!=1){
                            cur++;
                        }
                    }
                    else if(k<j){
                        if(nums[k]!=2){
                            cur++;
                        }
                    }
                    else{
                        if(nums[k]!=3){
                            cur++;
                        }
                    }
                }
                ans = min(ans, cur);
            }
        }
        return ans;
    }
};
