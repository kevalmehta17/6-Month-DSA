//arr = 102 2 1 3 101 100 4 3 3 6 5 103 
// sol = 6 bcz it is longest conse subsequ
//logic :- sort so :-  1 2 3 3 3 4 5 6 100 101 102 103 
// lsSmall store new num and previous num , started with else if bcz first num stored in lsSma cnt=1 bcz starts from it then i++ so we have to check  num - 1=lastnum bcz i++ means nums[1] = 2 so 2-1 = lassmaller 7 uodate lastsmal
//it also skips the duplicate that helps a lot

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        sort(nums.begin(),nums.end());
        int lastSmaller = INT_MIN;
        int count = 0;
        int longest = 1;
        //1 2 3 3 4 5 6 101 102 103
        for(int i = 0; i<n; i++){
            //
            if(nums[i]-1 ==lastSmaller){
                count++;
                lastSmaller = nums[i];
            }
            //for starting 
            else if(lastSmaller != nums[i]){
                count=1;
                lastSmaller = nums[i];
            }
            longest = max(longest,count);
        }
        return longest;

    }
};