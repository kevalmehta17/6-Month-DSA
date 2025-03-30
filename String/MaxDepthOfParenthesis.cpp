class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        int ans = 0;
        int countOfOpening = 0;

        for(int i =0; i<n; i++){
            if(s[i] == '(') {
                countOfOpening++;
            }
            else if(s[i] == ')'){
                countOfOpening--;
            }
            ans = max(ans,countOfOpening);
        }
        return ans;
        
    }
};