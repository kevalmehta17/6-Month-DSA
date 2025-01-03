class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n,0);

        prefix[0] = nums[0]; //first ele always stay inside the prefix
        for(int i = 1 ; i<n; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        //lets took the total sum
        long long total_sum = prefix[n-1];
        int count = 0;

        for(int i = 0; i<n-1; i++){
            long long total = total_sum - prefix[i];
            if(prefix[i] >= total ){
                count++;
            }
        }

        return count;
    }
};