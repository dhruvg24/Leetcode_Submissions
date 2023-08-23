class Solution {
public:
    string getPermutation(int n, int k) {
        string res = "";
        int fact = 1;
        vector<int> nums;
        for(int i = 1;i<n;i++){
            fact*=i;
            nums.push_back(i);
        }
        // eg n = 4
        // 1 + (2, 3, 4), 2 + (1,3,4), 3 + (1,2,4), 4+(1,2,3)
        // so 6, 6,6, 6 permutation in each case for getting cur num div by 6, for internally indexed position k%6
        nums.push_back(n);
        // so nums has 1...n value
        k--;
        // since we count from 0


        while(true){
            res+= to_string(nums[k/fact]);
            nums.erase(nums.begin() + k/fact);
            if(nums.size()==0)
                break;
            k%=fact;
            fact/=(nums.size());
            // for next iteration
        }
        return res;
    }
};

