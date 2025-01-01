// 1422 :- Max Score After Splitting a String leetcode

class Solution {
public:
    int maxScore(string s) {

        int n = s.length();
        int one_count = 0;
//         count the number of 1's in the string
        for(int i=0; i<n; i++){
            if(s[i] == '1'){
                one_count++;
            }
        }

        int zero_count = 0;
        int max_score = 0;
    //     iterate through the string and count the number of 0's and 1's
        for(int i =0;i<n-1; i++){
            if(s[i]=='1') one_count --;
            else{
                zero_count++;
            }
             max_score = max(max_score, zero_count+one_count);
        }

        return max_score;
    }
};