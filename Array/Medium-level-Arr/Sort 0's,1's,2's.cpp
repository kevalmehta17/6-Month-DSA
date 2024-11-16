//dutch flag algo
class Solution {
public:
    void sortColors(vector<int>& nums) {
        //dutch flag algo
        int n = nums.size();
        //left is for 0 and right is for 2 
        int left = 0;
        int right = n-1;
        int i =0;
        while(i<=right){
            if(nums[i]==0){
                swap(nums[left],nums[i]);
                left++;
                i++;
            }
            else if(nums[i]==2){
                swap(nums[i],nums[right]);
                right--;
            }
            else{
                i++;
            }
        }
        
        
        
    }
};