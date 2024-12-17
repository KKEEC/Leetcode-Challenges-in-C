#include <stdbool.h>
#include <stdio.h>

static int ft_strchr(char chr, char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == chr)
            return 1;
        i++;
    }
    return 0;
}

bool isValid(char* s) 
{
    int size = 0;
    while(s[size])
        size++;
    char stack[size];
    int top = -1;

    char opening[] = "([{";
    char closing[] = ")]}";

    int i = 0;
    while (s[i] != '\0')
    {
        if (ft_strchr(s[i], opening)) 
        {
            stack[++top] = s[i];
        }
        else if (ft_strchr(s[i], closing))
        {
            if (top == -1)
                return false;
            char openBracket = stack[top--];
            if ((s[i] == ')' && openBracket != '(') ||
                (s[i] == '}' && openBracket != '{') ||
                (s[i] == ']' && openBracket != '['))
                return false;
        }
        i++;
    }
    return top == -1;
}

int main()
{
    // Test case 1: Simple valid parentheses
    printf("Test case 1: %s -> %s\n", "()", isValid("()") ? "Valid" : "Invalid");

    // Test case 2: Simple valid brackets with different types
    printf("Test case 2: %s -> %s\n", "()[]{}", isValid("()[]{}") ? "Valid" : "Invalid");

    // Test case 3: Valid nested parentheses
    printf("Test case 3: %s -> %s\n", "(())", isValid("(())") ? "Valid" : "Invalid");

    // Test case 4: Invalid because of unbalanced parentheses
    printf("Test case 4: %s -> %s\n", "([)]", isValid("([)]") ? "Valid" : "Invalid");

    // Test case 5: Invalid because of missing closing bracket
    printf("Test case 5: %s -> %s\n", "(((", isValid("(((") ? "Valid" : "Invalid");

    // Test case 6: Valid mixed parentheses with matching types
    printf("Test case 6: %s -> %s\n", "([]){()}", isValid("([]){()}") ? "Valid" : "Invalid");

    // Test case 7: Invalid because of extra closing bracket
    printf("Test case 7: %s -> %s\n", "([{}])]", isValid("([{}])]") ? "Valid" : "Invalid");

    // Test case 8: Empty string
    printf("Test case 8: %s -> %s\n", "", isValid("") ? "Valid" : "Invalid");

    // Test case 9: Single type of valid bracket
    printf("Test case 9: %s -> %s\n", "(((((())))))", isValid("(((((())))))") ? "Valid" : "Invalid");

    // Test case 10: Valid nested brackets of all types
    printf("Test case 10: %s -> %s\n", "{[()()][]}", isValid("{[()()][]}") ? "Valid" : "Invalid");

    return(0);

}
