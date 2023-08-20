class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int, int> freq;
        int l=0 ,r=0, maxFreq=0,maxLen=0;
//         slide window
        while(r<n){
            if(freq.count(nums[r])==0){
                freq[nums[r]]=0;
            }
            freq[nums[r]]++;
            maxFreq=max(maxFreq, freq[nums[r]]);
            if((r-l+1)-(maxFreq)>k){
//                 i.e. except for max freq elem forming equal subarray if there are more than k distinct element move the window
                freq[nums[l]]--;
                l++;
            }
            r++;
            maxLen = max(maxLen, maxFreq);
        }
        return maxLen;
        
    }
};