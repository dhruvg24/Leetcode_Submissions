class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {
        map<long long, long long> mp;
        mp[0] = 1;
        int n = nums.size();
        long long cnt = 0, val = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]%mod == k){
                cnt++;
            }
            val += mp[(cnt - k)%mod];
            mp[cnt%mod]++;
        }
        return val;
    }
};