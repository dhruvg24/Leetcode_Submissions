#define ll long long
class Solution {
public:
    ll dp[1111][1<<11];
    vector<int> primes;
    int mod = 1e9+7;
    ll getMask(ll num){
        ll mask=0;
        for(int bit = 0;bit<10;bit++){
            int x = 0;
            while(num%primes[bit]==0)
            {
                x++;
                num/=primes[bit];
            }
            if(x>1)
                return -1;
                // if num gets div by prime >1 -> can be div by prime^2
            if(x==1)
                mask|=(1<<(bit+1)); //bit+1 -> for bit==0 -> prod 1  already took
        }
        return mask;
    }
    ll DFS(int idx, ll prodMask, vector<int> &nums){
        if(idx>=nums.size())
            return 1;
        if(dp[idx][prodMask]!=-1)
            return dp[idx][prodMask];
        ll mask = getMask(nums[idx]);
        ll ans=DFS(idx+1, prodMask, nums );
        if((prodMask & mask) == 0)
            ans = (ans + DFS(idx+1, prodMask|mask, nums))%mod;
        return dp[idx][prodMask]=ans;
    }
    int squareFreeSubsets(vector<int>& nums) {
        // prime factorise the product of subset, there exists 10 prime nums , since atmost 30 bits needed, for each prime represetnt as bit, dont pick or pick(if its prime mask and product prime mask -> not common bits)
        
        memset(dp, -1, sizeof(dp));
        primes = {2, 3, 5, 7, 11, 13,17, 19, 23, 29};
        return (DFS(0, 1, nums)-1 + mod)%mod;
        // need to exclude the empty pick case
    }
};