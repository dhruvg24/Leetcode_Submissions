class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        int cnt1 = 0, cnt2 = 0;
        for(auto it: nums1){
            sum1 += (it);
            if(it == 0){
                cnt1++;
            }
        }
        for(auto it: nums2){
            sum2+=it;
            if(it == 0){
                cnt2++;
            }
        }
        if((cnt1 == 0 && sum1<cnt2+sum2) || (cnt2==0 && sum2<cnt1 + sum1)){
            return -1;
        }
//         whichever is max of the two ... the other has to be converted to it
        return max(sum1+cnt1, sum2+cnt2);
    }
};