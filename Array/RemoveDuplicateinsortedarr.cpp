//logic:- here we have to count unique number in array & upfdate array so first k=1 then check if nums[i] != nums[i-1] then update into nums array and count k then return it
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty() == 0) return 0;
        int k = 1; // first element always unique

        for(int i = 1; i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};