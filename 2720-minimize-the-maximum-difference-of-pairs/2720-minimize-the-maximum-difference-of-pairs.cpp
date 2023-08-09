class Solution {
public:
    bool solve(vector<int> &nums, int mid, int p){
        int cnt=0;
        for(int i = 1;i<nums.size();i++){
            if(nums[i]-nums[i-1]<=mid){
                cnt++, i++;
            }
        }
        return cnt>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        // Bin search
        sort(nums.begin(), nums.end());
        int l=0, r = 1e9;
        int ans=0;
        int n = nums.size();
        while(l<=r){
            int mid = l+ (r-l)/2;
            if(solve(nums, mid, p))
            {
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};

