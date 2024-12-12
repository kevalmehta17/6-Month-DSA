//Approach :- First Take the Transpose the Array and reverse the row
//Step:- in transpose take a note so we can see diagonal same and left and right side of diagnol changes so chnage it through loop swap and then reverse the array

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i =0;i<n;i++){
            for(int j = i+1; j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i =0; i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};