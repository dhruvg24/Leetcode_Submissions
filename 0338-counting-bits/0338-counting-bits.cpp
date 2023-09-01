class Solution {
public:
    int solve(int n){
        // recursion
        // whenever we get number -> div by 2 
        // base cases: n == 0 | n == 1
        if(n == 0){
            // no set bit
            return 0;
        }
        if(n == 1){
            return 1;
        }
        if(n%2 == 0){
            return solve(n/2);
        }
        else{
            return 1 + solve(n/2);
        }
    }
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        for(int i = 0;i<=n;i++){
            ans[i] = solve(i);
        }
        return ans;
    }
};