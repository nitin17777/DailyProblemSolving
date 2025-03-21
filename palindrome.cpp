class Solution {
public:
    bool isPalindrome(int x) {
        // Step 1: Handle negative numbers and edge cases
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        // Step 2: Initialize variables to reverse the number
        int reversedNumber = 0;
        int original = x; // Store the original number for comparison later

        // Step 3: Reverse the digits of the number
        while (x > 0) {
            int digit = x % 10; // Extract the last digit of x
            reversedNumber = reversedNumber * 10 + digit; // Add the digit to the reversed number
            x /= 10; // Remove the last digit of x
        }

        // Step 4: Compare the reversed number with the original
        return original == reversedNumber;
    }
};
