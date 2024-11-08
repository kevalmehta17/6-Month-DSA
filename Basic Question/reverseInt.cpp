//logic :- simple exract last digit then divide it and then multiply it with 10 to add it to the next digit
//leetcode :- 7
class Solution {
public:
    int reverse(int x) {

     //123 =>321
        int reverseNum = 0;
        while(x!=0){
            int lastDigit = x%10;
            x=x/10;
            if(reverseNum >INT_MAX/10 ||(reverseNum==INT_MAX/10 && lastDigit>7)){
                return 0;
                //it is overflow
            }
            if(reverseNum <INT_MIN/10 || (reverseNum==INT_MIN/10 && lastDigit<-8)){
                return 0;
                //underflow
            }
            reverseNum = (reverseNum*10)+lastDigit;
        } 
        return reverseNum;
    }
};
