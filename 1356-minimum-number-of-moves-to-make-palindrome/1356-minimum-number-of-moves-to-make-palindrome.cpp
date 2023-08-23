class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        // try out using 2 ptr.
        int n = s.size();
        int i =0, j =n-1,k=0, moves = 0;
        while(i<j){
            if(s[i]==s[j])
                i++,j--;
            else{
                k = j;
                while(k>=i && s[k]!=s[i]){
                    k--;
                }
                if(k==i){
                    moves++;
                    swap(s[i], s[k+1]);
                    // eg ...b b ...
                    // make it ..b . b ... will make it palindromic
                }
                else{
                    while(k<j){
                        swap(s[k], s[k+1]);
                        k++, moves++;
                        // keep on swapping to make it reach to j
                        // ...b....b...
                        // ...b......b.
                    }
                    i++,j--;
                }
            }
        }
        return moves;
    }
};