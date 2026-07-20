#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
bool palindrome(const char *str,int start,int end)
{
    if(start>=end)
        return true;
    
    if(str[start]!=str[end])
        return false;
    return palindrome(str,start+1,end-1);
}
int main()
{

    char *str="Shivali";
    if(palindrome(str,0,strlen(str)-1)==true)
        printf("string is palindrome\n");
    else
        printf("String is not palindrome\n");
    return 0;
}