class Solution {
public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        vector<vector<int>> result;

        // Step 1: Sort the array
        sort(arr.begin(), arr.end());

        int left = 0;
        int right = arr.size() - 1;

        // Step 2: Use two-pointer technique
        while (left < right) {
            int sum = arr[left] + arr[right];

            if (sum == 0) {
                // Found a pair
                result.push_back({arr[left], arr[right]});
                
                // Skip duplicates on both sides
                int leftVal = arr[left];
                int rightVal = arr[right];
                while (left < right && arr[left] == leftVal) left++;
                while (left < right && arr[right] == rightVal) right--;
            } 
            else if (sum < 0) {
                // If sum is less than zero, increment left to increase sum
                left++;
            } 
            else if (sum > 0) {
                // If sum is greater than zero, decrement right to decrease sum
                right--;
            }
        }

        return result;
    }
};