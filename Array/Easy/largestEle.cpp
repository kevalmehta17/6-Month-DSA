//logic:-here initialize the k with int_min then check every element from loop and compare annd if it is greater than k then update k with that element

class Solution {
  public:
    int largest(vector<int> &arr) {
        int k = INT_MIN;
        for(int i =0 ;i<arr.size();i++){
            if(k<arr[i]){
                k=arr[i];
            }
        }
        return k;
    }
};