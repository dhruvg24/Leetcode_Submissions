class Solution {
public:
bool canCreate(int n, int machine, int mid, long long remBudget, vector<vector<int>> &composition, vector<int> &stock, vector<int> &cost){
    for(int i =0;i<n;i++){
        long long reqMetal = (long long)((long long)composition[machine][i]*mid);
        if(reqMetal>stock[i]){
            remBudget -= (reqMetal - stock[i])*(long long)cost[i];
        }
        if(remBudget<0){
            return false;
        }
    }
    return true;
}
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        // bin search
        int l = 0, r= INT_MAX;
        int ans = 0;
        while(l<=r){
            int mid = l + (r-l)/2;
            bool canMake = false;
            for(int i = 0;i<k;i++){
                if(canCreate(n, i, mid, budget, composition, stock, cost)){
                    ans = mid;
                    canMake = true;
                    l = mid+1;
                    break;
                }
            }
            if(canMake == false){
                r = mid-1;
            }
        }
        return ans;
    }
};