class Solution {
public:
     vector<int>temp,dp;
    int fn(int ind,vector<vector<int>>&offers)
    {
        if(ind>=offers.size())return 0;     
        if(dp[ind]!=-1)return dp[ind];    
        int Non_take=fn(ind+1,offers);  
        int target=lower_bound(temp.begin(),temp.end(),offers[ind][1]+1)-temp.begin();
        int take=offers[ind][2]+fn(target,offers);  
        return dp[ind]=max(Non_take,take);
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(),offers.end());
        for(auto it:offers)
            temp.push_back(it[0]);
			
        dp.resize(offers.size(),-1);
        return fn(0,offers);
    }
};