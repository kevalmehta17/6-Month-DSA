// logic :- simple first push back the first ele and always sort the arr and then compare across the arr and then acc. to condition push back to the ans
class Solution {
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        vector<vector<int>> ans;
        int n = arr.size();
        
        // Sort the intervals by the start time
        sort(arr.begin(), arr.end());
        
        // Add the first interval to the result
        ans.push_back(arr[0]);
        
        for (int i = 1; i < n; i++) {
            vector<int>& last = ans.back(); // Reference to the last interval in result
            vector<int>& current = arr[i]; // Current interval to process
            
            // Check if intervals overlap
            if (current[0] <= last[1]) {
                // Merge the intervals
                last[1] = max(current[1], last[1]);
            } else {
                // No overlap, add the current interval to result
                ans.push_back(current);
            }
        }
        
        return ans;
    }
};
