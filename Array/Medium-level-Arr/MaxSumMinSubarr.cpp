//Logic:-here we have to find sum of subarr smallest and secondSmallest so simply if we take more numb then hard to find max from it ex:-4+3=7 but in 4,3,1 sum=3+1=4 so we require only two num sum so logic is i =1 and sum =i-1 + i so we get only two num max Sum

// Input : arr[] = [4, 3, 1, 5, 6]
// Output : 11

class Solution {
  public:
    // Function to find pair with maximum sum
    int pairWithMaxSum(vector<int> &arr) {
        int n = arr.size();
        int sum =0;
        int maxSum = INT_MIN;
        for(int i = 1;i<n;i++){
            sum = arr[i-1]+arr[i];
            maxSum = max(maxSum,sum);
        }
        return maxSum;
    }
};