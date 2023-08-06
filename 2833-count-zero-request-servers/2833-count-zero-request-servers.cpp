class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        // using sliding window
        // need not search the logs completely better to think of sliding window
        // {time, serverid}
        // {query, idx}
        // i(start) and j(end)
        // window sz -> x
        // map -> storing the unique char in curr window
        // slide: remove the out of window characters
        // n - cnt of unique server id -> n - mp.size()
        int lgsize = logs.size(), qsize = queries.size();;
        vector<pair<int, int>> v; //{time, id} -> sort
        for(auto it: logs){
            v.push_back({it[1], it[0]});
        }
        sort(v.begin(), v.end());
        unordered_map<int, int>mp;
        // stores the unique servers currently
        vector<int> res(qsize, 0);
        vector<pair<int, int>> time(qsize); //{query, idx}
        for(int i=0;i<qsize;i++){
            time[i] = {queries[i], i};
        }
        sort(time.begin(), time.end());
        int i=0,j=0;
        // window set
        for(auto it: time){
            int curtime = it.first, idx = it.second;
            int start = 0;
            if(curtime - x>0){
                start = curtime-x;
            }
           
            int end = curtime;

            // we can move the r ptr until time in logs not more than end
            while(j<lgsize && v[j].first<=end){
                mp[v[j].second]++;
                j++;
            }
            // move i until not more than start

            while(i<lgsize && v[i].first<start){
                // remove elements
                if(mp[v[i].second]==1)
                    mp.erase(v[i].second);
                    // i.e. if single elem present remove from map
                else
                    mp[v[i].second]--;
                i++;
            }
            res[idx] = n - mp.size();
        }
        return res;
    }
};