class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();        // Number of rows
        int n = matrix[0].size();     // Number of columns
        int left = 0, right = n - 1;
        int top = 0, bottom = m - 1;
        vector<int> ans;

        // Continue traversing while boundaries are valid
        while (left <= right && top <= bottom) {
            // Traverse from left to right
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;

            // Traverse from top to bottom
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;

            // Traverse from right to left
            if (top <= bottom) { // Check to avoid duplicate row traversal
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // Traverse from bottom to top
            if (left <= right) { // Check to avoid duplicate column traversal
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return ans;
    }
};
