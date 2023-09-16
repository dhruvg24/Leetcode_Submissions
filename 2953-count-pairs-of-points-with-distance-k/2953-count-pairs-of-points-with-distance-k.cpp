class Solution {
public:
    int countPairs(vector<vector<int>>& c, int k) {
        // kind of 2 sum
        int n = c.size();
        int pairs = 0;
        map<pair<int, int>, int>mp;
        for(int i =0;i<n;i++){
            if(i!=0){
                int x = c[i][0], y = c[i][1];
                for(int i = 0;i<=k;i++){
                    int a = x^i, b = y^(k-i);
                    if(mp.find({a, b})!=mp.end()){
                        pairs+=mp[{a, b}];
                    }
                }
            }
            mp[{c[i][0], c[i][1]}]++;
        }
        return pairs;

    }
};

