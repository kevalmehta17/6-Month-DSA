//we have to rotate the array acc to k so if k=3 and array is [1,2,3,4,5,6,7] ,so ans = [5,6,7,1,2,3,4] so create temp vector arr then we have to push ele in temp through i+k bcz from it position to addup k and module for the rotate bcz of the end assume for 5 and index=4 so 4+3%7=0 so temp[0] = 5 for 6 index=5 5+3%7 = 1 so it goes index 1

class Solution{
    public:
    void rotate(vector<int>& nums,int k){
        vector<int> temp(nums.size());
        int n = nums.size();
        for(int i = 0;i<n;i++)[
            temp[(i+k)%n] = nums[i];
        ]
        nums = temp;

    }
}