//Kadane's ALgo
//Here we have to find the maxSum subarray value so simple first take sum and maxSum varibale then iterate through the array and check if current element is greater than sum then update sum and maxSum after most important that if value of sum is less then Zero then we give Sum = 0 and break subarray bcz there is no point to add negative value in sum and again add current ele in sum and if after that negative comes but not make sum less then zero we put in subarray and find the maxSum

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int maxSum = INT_MIN;

        for(int i =0;i<n;i++){
            sum +=nums[i];
            maxSum = max(maxSum,sum);
            if(sum<0) return sum;
        }
        return maxSum;
    }
};


// Time Complexity is higher so not a best case
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int maxSum = INT_MIN;
    // int n = nums.size();

    // // Iterate over all possible starting points of subarrays
    // for (int i = 0; i < n; i++) {
    //     int currentSum = 0;

    //     // Expand the subarray from index i to j and update the sum dynamically
    //     for (int j = i; j < n; j++) {
    //         currentSum += nums[j];  // Add nums[j] to the current subarray sum
    //         maxSum = max(maxSum, currentSum);  // Update maxSum if currentSum is larger
    //     }
    // }

    // return maxSum
        
//     }
// };