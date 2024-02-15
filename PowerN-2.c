#include <stdbool.h>
#include<stdio.h>
bool isPowerofTwo(long long int n) {
    // If n is less than or equal to 0, it's not a power of 2
    if (n <= 0) {
        return false;
    }
    // Loop until n becomes 1
    while (n > 1) {
        // If n is not divisible by 2, it's not a power of 2
        if (n % 2 != 0) {
            return false;
        }
        // Divide n by 2
        n /= 2;
    }
    // If n becomes 1, it's a power of 2
    return true;
}
