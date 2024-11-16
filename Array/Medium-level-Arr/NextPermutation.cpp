//logic:-inside the code it looks hard but algo and steps make it easy,
//1)we have to find breakpoint where it can be next permutated in ascending order so
//findout arr[i]<arr[i+1] then findout close great num from back bcz of bottom to up graph it easy and then swap it and reverse the num from index+1 
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //First we have to findout thr breakpoint
        //the graph of arrays values from the end of array is increasing form
        //so we have to find the break where nums[i]<nums[i+1] 
        int index = -1;
        int n = nums.size();

        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                //if it does then we found the breakpoint
                index = i;
                break;
            }
            
        } 
        // Step 2: If no breakpoint is found, reverse the entire array
        if (index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }  
        //now after finding the breakpoint we have to swap if with the greater num close to it
        for(int i=n-1;i>=0;i--){
            if(nums[i]>nums[index]){
                swap(nums[i],nums[index]);
                break;
    //here the graph of num from ending of arr is always increasive form we if any number we found greater then nums[index] is very close to it           
            }
        }    
        //after swapping we have to build num more smaller so we ordered it in ascending right after the swapped number
        reverse(nums.begin()+index+1,nums.end());
        
    }
};