#include <iostream>
class Solution {
  public:
    void print_divisors(int n) {
        
      for(int i = 1; i<=n;i++){
          if(n%i == 0){
              cout << i <<" ";
          }
          
      }
    
      
    }
    
};