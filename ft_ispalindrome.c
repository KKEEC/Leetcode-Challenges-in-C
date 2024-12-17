#include <stdbool.h>
#include <stdio.h>

bool isPalindrome(int x)
{
    int reversed;
    
    reversed = 0;
    if (x < 0 || (x % 10 == 0 && x != 0))
        return 0;
    while (x > reversed)
    {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    if (x == reversed || x == reversed / 10)
        return 1;
    else 
        return 0;
}

int main() 
{
     // List of test cases
    int test_cases[] = {121, 12321, 0, 9999, -121, -1, 10, 100, 1000, 7, 9, 123, 56789, 45654};
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    // Run and print the test results
    for (int i = 0; i < num_tests; i++) {
        printf("Number: %d, isPalindrome: %d\n", test_cases[i], isPalindrome(test_cases[i]));
    }
    return 0;
}