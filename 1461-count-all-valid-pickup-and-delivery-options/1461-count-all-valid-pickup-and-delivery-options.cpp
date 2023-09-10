class Solution {
public:
    int mod = 1e9+7;
    int countOrders(int n) {
        long long cnt=1;
        for(int i = 2;i<=n;i++){
            cnt =((2*i-1)*cnt*i)%mod;
        }
        return (int)cnt;
    }
};