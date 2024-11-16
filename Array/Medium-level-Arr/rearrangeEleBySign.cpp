//Optimal Approach :- O(n)
//Logic:-Here rather then using two loop for +ve and -ve , we create new vector & acc. to output positiveIndex must start from 0 & negativeIndex must start from 1
// so give that condition and iterate through loop and if num is >0 we add it and increase it by +2 so other postive number can store at that index and same for -ve!!
// Input: nums = [3,1,-2,-5,2,-4]
// Output: [3,-2,1,-5,2,-4]
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int positiveIndex = 0;
        int negativeIndex = 1;
        vector<int> result(n,0);
        for(int i=0;i<n; i++ ){
            if(nums[i]>0){
                result[positiveIndex] = nums[i];
                positiveIndex+=2;
            }
            else{
                result[negativeIndex] = nums[i];
                negativeIndex +=2;
            }
        }
        return result;
    }
};

//variety Imp:----------------
//logic:- first put pos and neg as brute force approach then figure how to manage if the any of this value is higher then otheone so firstly we use && oprator that if both is true till fill the arr then simple we itrate remaing ele to the arr in both pos and neg 
//this question looks simple code but the question conditions makes it hard one 
class Solution {
  public:
    void rearrange(vector<int> &arr) {
        int n = arr.size();
        vector<int> positive,negative;
        
        for(int i = 0; i<n; i++){
            if(arr[i]>=0){
                positive.push_back(arr[i]);
            }
            else{
                negative.push_back(arr[i]);
            }
        }
        int posIndex = 0,negIndex = 0,index=0;
        //adding to the arr
        //we have to iterate till the max size of both
        while(posIndex<positive.size() && negIndex<negative.size()){
            arr[index++] = positive[posIndex++];
            arr[index++] = negative[negIndex++];
        }
        
        
        //for remaing positive value
        while(posIndex<positive.size()){
            arr[index] = positive[posIndex++];
            index++;
        }
        //for remaing negative value
        while(negIndex<negative.size()){
            arr[index] = negative[negIndex++];
            index++;
        }
        
    }
};


//Brute Force:-
// //Logic:-here the logic is to first create to vector postive and negative and 
// through loop iteration push back +ve and -ve then create new vector and based on index arrange it with complextiy O(n*2)


class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>positive,negative;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                positive.push_back(nums[i]);

            }
            else{
                negative.push_back(nums[i]);
            }
        }
        vector<int> result(nums.size());
        int positiveIndex = 0; 
        int negativeIndex = 0;
        for(int i =0; i<n; i++){
            if(i%2==0){
                result[i] = positive[positiveIndex++];
            }
            else{
                result[i] = negative[negativeIndex++];
            }
        }
        return result;
    }
};