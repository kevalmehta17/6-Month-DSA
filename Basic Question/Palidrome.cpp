//Logic :- Here we have check that the reverse of the num is same , so first if num contains 0 at last so reverse is not possible so return false then extract lastDigit through module and /10 and then check is it equal to origin or not! 


class Solution {
public:
    bool isPalindrome(int x) {

    if(x < 0 || x%10==0 && x!=0) return false;
        int original = x;
        int reverseNum = 0;
        while(x!=0){
           int lastDigit = x%10;
           if(reverseNum>(INT_MAX-lastDigit)/10) return false;
           reverseNum=(reverseNum*10)+lastDigit;
           x/=10;
            
        }
         if(reverseNum == original){
            return true;
        }
        return false;

    }
};