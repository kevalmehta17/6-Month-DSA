//logic :- here simple we have add one by one in each index so we add in sum varible and then update the nums array with the sum of the previous two numbers
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum +=nums[i];
            nums[i] = sum;
        }
        return nums;
    }
};