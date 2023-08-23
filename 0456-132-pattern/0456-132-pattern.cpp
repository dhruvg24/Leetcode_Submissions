class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n= nums.size();
        stack<int> st;
        int s3 = INT_MIN;
        for(int i = n - 1;i>=0;i--){
            if(nums[i]<s3)
                return true;
                // s1<s3<s2
            else{
                while(!st.empty() && nums[i]>st.top()){
                    s3 = st.top();
                    st.pop();
                    // popping s3
                }
            }
            st.push(nums[i]);
            // pushin s2
        }
        return false;
    }

};