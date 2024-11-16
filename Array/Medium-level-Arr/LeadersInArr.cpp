//optimal
//logic:-simple here we have to add end num to result then if any num is higher then maxiRight then it must me higher then other so add it and return
class Solution {
public:
    // Function to find the leaders in the array.
    vector<int> leaders(vector<int>& arr) {
        vector<int> result;
        int n = arr.size();
        int maxRight = arr[n - 1]; // Initialize with the rightmost element
        result.push_back(maxRight); // Rightmost element is always a leader

        // Traverse the array from second last to the first element
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] >= maxRight) {
                result.push_back(arr[i]);
                maxRight = arr[i]; // Update maxRight
            }
        }

        // Reverse the result as we traversed from right to left
        reverse(result.begin(), result.end());
        return result;
    }
};






//brute force:'
// started from 0th position assume first ele is leader and iterate over the arr
// if arr[i]>after  all participate then add arr[i]
//Time com:-O(n2)


class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        vector<int> result;
        int n = arr.size();
        for(int i=0;i<n; i++){
            bool leader = true;
            for(int j = i+1; j<n;j++){
                if(arr[j]>arr[i]){
                    leader = false;
                    break;
                }
            }
            if(leader){
                result.push_back(arr[i]);
            }
        }
        return result;
    }
};
