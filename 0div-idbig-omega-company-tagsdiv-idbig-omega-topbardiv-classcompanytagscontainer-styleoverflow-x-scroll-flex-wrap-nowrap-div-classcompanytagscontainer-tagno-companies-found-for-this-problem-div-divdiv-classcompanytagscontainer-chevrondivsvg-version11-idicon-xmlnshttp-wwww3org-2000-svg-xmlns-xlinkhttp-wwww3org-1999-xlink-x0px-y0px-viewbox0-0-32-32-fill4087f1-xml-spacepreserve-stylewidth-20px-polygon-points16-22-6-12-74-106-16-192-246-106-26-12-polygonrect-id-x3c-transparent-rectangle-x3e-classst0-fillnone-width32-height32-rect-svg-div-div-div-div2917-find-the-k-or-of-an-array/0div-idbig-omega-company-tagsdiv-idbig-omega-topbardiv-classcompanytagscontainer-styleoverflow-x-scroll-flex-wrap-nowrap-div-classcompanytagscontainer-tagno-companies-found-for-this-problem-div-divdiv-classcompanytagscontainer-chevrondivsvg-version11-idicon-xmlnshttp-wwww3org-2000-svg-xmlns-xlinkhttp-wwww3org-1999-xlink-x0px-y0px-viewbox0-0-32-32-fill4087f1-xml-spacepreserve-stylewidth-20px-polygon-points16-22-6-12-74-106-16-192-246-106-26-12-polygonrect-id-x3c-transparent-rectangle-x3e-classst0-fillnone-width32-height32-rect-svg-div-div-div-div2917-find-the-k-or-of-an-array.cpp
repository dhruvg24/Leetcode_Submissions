class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
//         need to cnt set bits
        long long sum = 0;
        int n = nums.size();
        for(int i = 0;i<32;i++){
            int cnt = 0;
            for(auto it: nums){
//                 check if bit is set
                if(it & (1<<i)){
                    cnt++;
                }
                
            }
            if(cnt>=k){
                sum+=(pow(2, i));
            }
        }
        return (int)sum;
    }
};