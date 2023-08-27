class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        long long sum = 0;
        int minOp = 0;
        vector<int> freq(32);
        // for target -> represented in binary format
        // we will keep the frequency of each position for nums[i]
        // so that if present at that pos in target will include else we move from right to left, and split accordingly and combine 2^x and 2^x to make freq of 2^(x+1), in some cases need to split (operations++) when at some greater pos freq of 1 is present but requirement at lower position
        for(auto it: nums){
            sum+=it;
            int curPow = int(log(it)/log(2));
            freq[curPow]+=1;

        }
        // trivial case

        if(sum<target){
            return -1;
        }
        int minIdx = 32;
        // this minIdx tells the requirement of 2^minIdx
        // check for every bit in target
        for(int i = 0;i<31;i++){
            int bit = (1<<i);
            if((target&bit)>0){
                // that means at that pos it is needed
                if(freq[i]>0)
                    freq[i]--;
                else
                    // need of 2^i
                    // from r->l
                    minIdx = min(minIdx, i);
            }
            // lets say in target curr bit is not needed but we need some smaller bit at some prev index... need to split
            if(freq[i]>0 && minIdx<i){
                minOp += (i - minIdx);
                // that many operations will be done 
                // eg 2^4 -> 2^3 2^2

                freq[i]--;
                // again set minIdx to 32
                minIdx = 32;
            }

            // now combine the bits each time while moving r->l, so that it leads to min op
            freq[i+1] += freq[i]/2;
            // combining numbers to make freq at higher number 

        }
        return minOp;
    }
};
