#include <stdio.h>
static int ft_strchr(char c, char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == c)
        {
            return i;
        }
        i++;
    }
    return (-1);
}

int romanToInt(char* s) 
{
    char roman[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int value[] = {1, 5, 10, 50, 100, 500, 1000};
    
    int i = 0;
    int result = 0;
    
    while (s[i] != '\0')
    {
        int left = ft_strchr(s[i], roman);  
        if (left == -1) 
        {
            return -1; 
        }

        int right = -1;
        
        if (s[i + 1] != '\0') {
            right = ft_strchr(s[i + 1], roman);
            if (right == -1) {
                return -1;
            }
        }
        if (right != -1 && value[left] < value[right]) 
        {
            result -= value[left];
        } else {
            result += value[left];
        }

        i++;
    }

    return result;
}

int main(void) 
{
    // Test cases
    printf("III = %d\n", romanToInt("III"));  // 3
    printf("IV = %d\n", romanToInt("IV"));    // 4
    printf("IX = %d\n", romanToInt("IX"));    // 9
    printf("XIII = %d\n", romanToInt("XIII"));// 13
    printf("LVIII = %d\n", romanToInt("LVIII")); // 58
    printf("MCMXCIV = %d\n", romanToInt("MCMXCIV")); // 1994
    return 0;
}