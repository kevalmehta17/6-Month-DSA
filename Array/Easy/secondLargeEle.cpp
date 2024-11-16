//logic:- first findout the firstlargest & also update the secondLargest & else if find second Largest and is not equal to firstlargest and update  the secondLagest ,now if secondLargest is not availabe due to edge case then return -1 else retun the secondLargest

class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {

        int firstLargest = INT_MIN;
        int secondLargest = INT_MIN;

        for(int i = 0; i<arr.size();i++){
            if(firstLargest<arr[i]){
                secondLargest = firstLargest;
                firstLargest = arr[i];
            }
            else if(secondLargest<arr[i]&& arr[i]!=firstLargest){
                secondLargest = arr[i];
        }
        return (secondLargest == INT_MIN) ? -1 : secondLargest;
    }

};