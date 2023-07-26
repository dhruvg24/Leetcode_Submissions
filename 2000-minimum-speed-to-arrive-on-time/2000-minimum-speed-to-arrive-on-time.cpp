class Solution {
public:
    bool canReach(vector<int> &dist, double hour, int speed){
        double timeTaken = 0;
        for(int i = 0;i<dist.size()-1;i++){
            //need to take interger hours only
            // timeTaken+=(dist[i])/speed;
            timeTaken+=((dist[i]+speed-1)/speed);
        }
        // for the last train journey not int hour not to be checked
        timeTaken+=((double)dist.back())/speed;
        return timeTaken<=hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        // dist[i] = dist taken by particular train
        // hour - amt of time to reach office
        // bin search
        // check for all speeds and find min of it
        int n = dist.size();
        int l = 1, r = 1e7;
        if(hour<=dist.size()-1)
            return -1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(canReach(dist, hour, mid))
                r = mid-1;
            else
                l = mid+1;
        }
        return l;
    }
};