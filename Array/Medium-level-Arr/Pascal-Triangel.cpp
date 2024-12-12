//here logic is that we have to minus col from row and multiple it with the previous
// then divide it with col

class Solution {
public:

    vector<int> generateRow(int row) {
        long long ans = 1; // Initialize the first value in the row as 1
        vector<int> ansRow; // Vector to store the row elements
        ansRow.push_back(1); // The first element of every row is 1
        for(int col = 1; col < row; col++) {
            ans = ans * (row - col); // Calculate the next element
            ans = ans / col;        // Divide by column index to maintain correctness
            ansRow.push_back(ans);  // Append the calculated value to the row
        }
        return ansRow; // Return the complete row
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans; // 2D vector to store Pascal's Triangle
        for(int i = 1; i <= numRows; i++) {
            ans.push_back(generateRow(i)); // Generate and add each row
        }
        return ans; // Return the complete Pascal's Triangle
    }
};
