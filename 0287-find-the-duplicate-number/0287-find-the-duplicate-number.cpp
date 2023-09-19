class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n =nums.size();
        for(int i=0;i<n;i++)
        {
            int tmp=abs(nums[i]);
            if(nums[tmp-1]>=0){
                nums[tmp-1]*=-1;
            }
            else{
                return tmp;
            }
        }
        return 0;
    }
};
