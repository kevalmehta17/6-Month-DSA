#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // Sort the array
        
        for (int i = 0; i < nums.size() - 1; i += 2) {
            if (nums[i] != nums[i + 1]) {
                return nums[i];  // Return the element without a pair
            }
        }
        
        // If no single element found in pairs, the last element is the single one
        return nums[nums.size() - 1];
    }
};
