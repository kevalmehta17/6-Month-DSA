//geeksforgeeks
//logic:-we have to count no of times whole num is divided from one by one single num from original num and give 0 
//first we extract one by one number and then we check if it is divisor of original num or not if yes then we count it and if no
class Solution {
  public:
    // Function to count the number of digits in n that evenly divide n
    int evenlyDivides(int n) {
        int count = 0;
       int original = n;
       while(n!=0){
        int digit = n%10;
        n/=10;
        if(digit!=0&& original%digit==0){
            count++;
        }

       }
       return count;
    }
};