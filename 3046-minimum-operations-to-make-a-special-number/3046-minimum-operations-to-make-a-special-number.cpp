class Solution {
public:
    int minimumOperations(string num) {
        // can make last 2 dig to be 00/25/50/75
        int n = num.size();
        bool found0 = false, found5 = false;
        for(int i = n-1;i>=0;i--){
            if(found0 && num[i] == '0' )
                return (n-2-i);
            if(found0 && num[i]=='5'){
                return (n-2-i);
            }
            if(found5 && num[i]=='2'){
                return (n-2-i);
            }
            if(found5 && num[i]=='7'){
                return (n-2-i);
            }
            if(num[i]=='0')
                found0=true;
            if(num[i]=='5')
                found5 = true;
        }
        if(found0)
            return n - 1;
        return n;
    }
};