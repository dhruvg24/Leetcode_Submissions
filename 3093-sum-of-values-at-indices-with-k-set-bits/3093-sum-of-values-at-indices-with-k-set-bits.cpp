class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        for(int i = 0;i<n;i++){
            int cnt = 0;
            int tmp = i;
            while(tmp){
                cnt+=(tmp&1);
                tmp = tmp>>1;
            }
            if(cnt == k){
                ans+=nums[i];
            }
        }
        return ans;
    }
};