//logic:-the cube of each digit in num = to the original num, so one by one extract each num then cube it and add it to the result and check it
class Solution {
  public:
    bool armstrongNumber(int n) {
        int original = n;
        int sum =0;
        while(n!=0){
            int lastDigit = n%10;
            sum += (lastDigit*lastDigit*lastDigit);
            n/=10;
        }
        return original == sum;
        
    }
};