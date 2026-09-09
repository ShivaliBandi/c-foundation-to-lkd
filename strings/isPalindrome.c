#include"header.h"
bool  isPalindrome(char *str)
{
    if(str==NULL || (strlen(str)==0))
    {
        printf("String is empty\n");
        return 0;
    }
    int start=0,end=strlen(str)-1;
    while(start<end)
    {
        if(str[start]==' ')
            start++;
        else if(str[end]==' ')
            end--;
        else if(str[start]!=str[end])
            return 0;
        else 
        {
            start++;
            end--;
        }
        
    }
    return 1;
}
int main()
{
   
    char str[100];
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    if(isPalindrome(str)==0)
        printf("string is not palindrome\n");
    else
        printf("String is palindrome\n");
        
    return 0;
}