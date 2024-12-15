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