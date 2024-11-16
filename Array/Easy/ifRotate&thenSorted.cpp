//logic :- nums = [3,4,5,1,2] if we rotate at x= 3 then we can sort that so we have to check possibilty so logic is simple direct jump to for loop if num[i]>num[i+1]%n it check all posibility to rotate array and if it is possible then increase rotatechance and if increase by 1 then there is no chance to rotate array and return false else return true
class Solution {
public:
  //3 4 5 1 2
    bool check(vector<int>& nums) {
        int n =nums.size();
        int rotateChance = 0;
        vector<int> isSorted = nums;
        sort(isSoretd.begin(),isSoted.end());
        if(isSorted == nums) return true;

        for(int i = 0;i<n;i++){
            if(nums[i]>nums[i+1]%n){
                rotateChance++;
            }
            if(rotateChance>1){
                return false;
            }
        }
        return true;

    }
};