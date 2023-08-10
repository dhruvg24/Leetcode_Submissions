class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        
        while(low <= high)
        {
            int mid = low + (high-low) / 2;
            if (nums[mid] == target)
                return true;
			// with duplicates we can have this contdition, update left & right
            if((nums[low] == nums[mid]) && (nums[high] == nums[mid]))
            {
                low++;
                high--;
            }
			// first half
			// first half is in order
            else if(nums[low] <= nums[mid])
            {
				// target is in first  half
                if((nums[low] <= target) && (nums[mid] > target))
                    high = mid - 1;
                else
                    low = mid + 1;
            }
			// second half
			// second half is order
			// target is in second half
            else
            {
                if((nums[mid] < target) && (nums[high]>= target))
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return false;
    }
};