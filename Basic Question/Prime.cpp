#include <cmath> // For sqrt function

class Solution {
public:
    int isPrime(int N) {
        if (N <= 1) return 0; // 1 and any number less than 1 are not prime
        if (N <= 3) return 1; // 2 and 3 are prime numbers
        
        // Only check up to the square root of N
        for (int i = 2; i <= sqrt(N); i++) {
            if (N % i == 0) {
                return 0; // Not prime if divisible by any number up to sqrt(N)
            }
        }
        return 1; // Prime if no divisors were found
    }
};

