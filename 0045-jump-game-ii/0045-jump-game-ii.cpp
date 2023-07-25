class Solution {
public:
    int jump(vector<int>& nums) {
        //1 - D approach
        int n = nums.size();
        if(n<2) return 0;
        int curMax=0,nextMax=0, cntJumps=0;
        for(int i = 0;i<n-1;i++){
            nextMax= max(nextMax, i+nums[i]);
            if(i==curMax){
                cntJumps++;
                curMax=nextMax;
            }
        }
        return cntJumps;
    }
};

