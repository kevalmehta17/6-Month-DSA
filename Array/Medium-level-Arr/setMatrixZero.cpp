class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Step 1: Initialize flags
        bool firstrow = false, firstcol = false;

        // Step 2: Mark the first row and column
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    if (i == 0) firstrow = true; // Mark first row
                    if (j == 0) firstcol = true; // Mark first column
                    matrix[0][j] = 0; // Mark column
                    matrix[i][0] = 0; // Mark row
                }
            }
        }

        // Step 3: Replace inner matrix based on markers
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0; // Set zero based on markers
                }
            }
        }

        // Step 4: Handle first row
        if (firstrow) {
            for (int j = 0; j < matrix[0].size(); j++) {
                matrix[0][j] = 0; // Set all elements in the first row to zero
            }
        }

        // Step 5: Handle first column
        if (firstcol) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0; // Set all elements in the first column to zero
            }
        }
    }
};
