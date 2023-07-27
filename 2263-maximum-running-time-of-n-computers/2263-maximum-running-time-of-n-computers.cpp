class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        // using Bin. search 
        // check if all comp can be run for m unit of time
        // n*m -> total hours
        // we take power of all batteries -> <=m from each
        // if enough power for n*m hours-> so for m hours simultaneously can be run

        long long l=0,r=0;
        long long total=0;
        for(auto it: batteries){
            total+=(it);
        }
        r = total/n;
        while(l<r){
            long long mid = (l+r+1)/2;
            // this is for taking integer units of time
            long long timeOperated = 0;

            for(auto it: batteries){
                timeOperated+=min(((long long)it), mid);
            }
            if(timeOperated>=n*mid){
                l = mid;
            }
            else{
                r = mid - 1;
            }
        }
        return l;
    }
};