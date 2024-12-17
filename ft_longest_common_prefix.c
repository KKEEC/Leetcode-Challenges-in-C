#include <stdlib.h>
#include <stdio.h>

int ft_strcmp(char *str1, char *str2)
{
    int i = 0;
    while (str1[i] && str2[i])
    {  
        if (str1[i] != str2[i])
            return i;  
        i++;
    }
    return (i);
}


char* longestCommonPrefix(char** strs, int strsSize) 
{
    if (strsSize == 0) 
        return ""; 
    
    int i = 1;
    int countelem;
    char *currentprefix = strs[0];
    char *updatedprefix;
    
    while (i < strsSize)
    {
        countelem = ft_strcmp(currentprefix, strs[i]);
        if (countelem == 0)
            return "";
        updatedprefix = malloc(sizeof(char) * (countelem + 1));
        if (!updatedprefix) 
            return "";
        int j = 0;
        while (j < countelem)
        {
            updatedprefix[j] = strs[0][j];
            j++;
        }
        updatedprefix[countelem] = '\0';

        if(currentprefix != strs[0])
            free(currentprefix);
        currentprefix = updatedprefix;

        i++;
    }
    
    return currentprefix;
}
int main() {
    // Test case 1: All strings are the same
    char *strs1[3] = {"flower", "flower", "flower"};
    char *result1 = longestCommonPrefix(strs1, 3);  // Call function to get result
    printf("Test case 1: %s\n", result1);  // Expected output: "flower"
    free(result1);  // Free dynamically allocated memory

    // Test case 2: No common prefix
    char *strs2[3] = {"dog", "racecar", "car"};
    char *result2 = longestCommonPrefix(strs2, 3);
    printf("Test case 2: %s\n", result2);  // Expected output: ""
    free(result2);

    // Test case 3: One string is a prefix of another
    char *strs3[3] = {"interview", "internet", "internal"};
    char *result3 = longestCommonPrefix(strs3, 3);
    printf("Test case 3: %s\n", result3);  // Expected output: "inter"
    free(result3);

    // Test case 4: Strings with varying lengths
    char *strs4[4] = {"cat", "car", "cater", "cattle"};
    char *result4 = longestCommonPrefix(strs4, 4);
    printf("Test case 4: %s\n", result4);  // Expected output: "cat"
    free(result4);

    // Test case 5: One string is empty
    char *strs5[3] = {"", "dog", "door"};
    char *result5 = longestCommonPrefix(strs5, 3);
    printf("Test case 5: %s\n", result5);  // Expected output: ""
    free(result5);

    // Test case 6: Only one string
    char *strs6[1] = {"apple"};
    char *result6 = longestCommonPrefix(strs6, 1);
    printf("Test case 6: %s\n", result6);  // Expected output: "apple"
    free(result6);

    // Test case 7: Mixed common prefixes with different string lengths
    char *strs7[4] = {"florida", "flour", "flow", "flight"};
    char *result7 = longestCommonPrefix(strs7, 4);
    printf("Test case 7: %s\n", result7);  // Expected output: "fl"
    free(result7);

    return 0;

}
