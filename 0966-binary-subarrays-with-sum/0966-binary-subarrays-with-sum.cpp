class Solution {
public:
    int cntFunc(vector<int> &nums, int goal){
        int i=0,j=0, sum=0, ans=0;
        while(j<nums.size()){
            sum+=nums[j];
            while(i<=j && sum>goal){
                sum-=nums[i++];
            }
            // cout<<j-i+1<<" ";
            ans+=(j-i+1);
            j++;
        }
        // cout<<":"<<ans<<" ";
        return ans;

    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return cntFunc(nums, goal) - cntFunc(nums, goal-1);
        // function is to get subarray less than or equal to goal(as passed)
    }
};



