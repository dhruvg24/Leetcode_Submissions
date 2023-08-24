class Solution {
public: 
    long long getCost(vector<int> &nums, vector<int> &cost, int mid){
        long long ans = 0;
        for(int i = 0;i<nums.size();i++){
            // making nums[i] equal to mid would cost difference*cost[i]
            // and this gets add up
            ans+=1L*abs(nums[i] - mid)*cost[i];
        }
        return ans;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        // the cost function will lie bw min and max of the nums array element
        // cost is like more away we go from the number, the greater will be the cost
        // can use binary search
        long long ans = 0;
        int l = 0, r = 0;
        for(int i = 0;i<nums.size();i++){
            l = min(nums[i], l);
            r = max(nums[i], r);
        }
        while(l<=r){
            int m = l + (r - l)/2;
            long long c1 = getCost(nums, cost, m);
            long long c2 = getCost(nums, cost, m + 1);
            ans = min(c1, c2);
            (c1>c2?(l = m+1):(r = m-1));
            // i.e. if cost(Mid)>cost(Mid+1) => min is to right, else min at left
        }
        return ans;
    }
};