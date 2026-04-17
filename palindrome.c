#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void stringcheckpalindrome(char str[], int size);
void arrcheckpalindrome(int arr[], int size);
int main()
{
    printf("**** PALINDROME CHECKER ****\n");
    int size1, size2;
    printf("Enter the size of your string: ");
    scanf("%d", &size1);
    getchar();
    
    char *str = (char *)malloc((size1) * sizeof(char));
    printf("Enter the string you wish to check for palindrome: ");
    scanf("%s", str);
    getchar();
    stringcheckpalindrome(str, size1);
    free(str);
    
    printf("Enter the size of your array: ");
    scanf("%d", &size2);
    int *arr = (int *)malloc(size2 * sizeof(int));
    for (int i = 0; i < size2; i++)
    {
        printf("Enter integer %d: ", i+1);
        scanf("%d", &arr[i]);
        getchar();
    }
    arrcheckpalindrome(arr, size2);
    free(arr);
    return 0;
}
void stringcheckpalindrome(char str[], int size)
{
    char newStr[size + 1];
    for (int i = 0; i < size;i++)
    {
        newStr[i] = str[size - 1 - i];
    }
     newStr[size] = '\0';
    if (strcmp(newStr, str) == 0)
    {
        printf("Your string is palindrome\n");
    }
    else
    {
        printf("Your string is not palindrome\n");
    }
}
void arrcheckpalindrome(int arr[], int size)
{
    int isPalindrome = 1;
    int newArr[size], j = 0;
    for (int i = size; i >= 0;i--)
    {
        newArr[j] = arr[i - 1];
        j++;
    }
     for (int i = 0; i < size;i++)
    {
        if (newArr[i] != arr[i])
        {
            isPalindrome = 0;
            break;
        }
    } 
    if (isPalindrome)
        {
            printf("Your array is palindrome\n");
        }
    else
        {
            printf("Your array is not palindrome\n");
        }
}
