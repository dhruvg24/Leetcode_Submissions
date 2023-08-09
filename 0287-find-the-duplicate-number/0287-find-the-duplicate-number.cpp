class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    //    different approach by finding the cycle
        int slow = 0, fast= 0;
        do{
            slow = nums[slow], fast = nums[nums[fast]];

        }while(slow!=fast);

        // set slow to start again
        slow = 0;
        while(slow!=fast){
            slow = nums[slow], fast = nums[fast];
        }
        return slow;
        // now this will be the duplicate number
    }
};
