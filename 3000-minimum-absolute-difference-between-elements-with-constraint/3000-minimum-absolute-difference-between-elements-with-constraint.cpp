class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        // brute force - TLE 
        // need to optimise so that to minimise the difference
        // lets say {i,j}-> valid indexes
        // for any j we find the lower_bound that will minimise the difference(closest greater val) -> using set
        // need to also see the closest smaller val
        // and store the differnce
        int minDiff = INT_MAX, n = nums.size();
        set<int> st;
        for(int j = x;j<n;j++){
            // i...j 
            // j - i==x initially taken
            int i = j - x;
            st.insert(nums[i]);

            // get closest greater val
            auto justGreater = st.lower_bound(nums[j]);
            if(justGreater==st.end()){
                justGreater--;
            }
            int curDif = abs(nums[j]-(*justGreater));
            minDiff = min(curDif, minDiff);
            if(justGreater==st.begin())
                continue;
            
            // now need to get the closest smaller value
            justGreater--;
            // pointer
            curDif = abs(nums[j]-(*justGreater));
            minDiff = min(minDiff, curDif);

        }
        return minDiff;

    }
};

