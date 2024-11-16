///logic:- first nonZeroIndex =0 if element is 0 then we dont swap but i++ means gradually increase but nonZeroIndex not so when nonzero value come it swap with nonZeroIndex variable so zeroes put at the end 
class Solution{
    public:
      void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int nonZeroIndex = 0;

        for(int i = 0; i<n;i++){
            if(nums[i]!=0){
                swap(nums[i],nums[nonZeroIndex]){
                    nonZeroIndex++;
                }
            }
        }
      }
}