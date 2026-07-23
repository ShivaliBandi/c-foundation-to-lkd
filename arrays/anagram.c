#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
bool anagram( char *str1, char *str2)
{
    if(strlen(str1)!=strlen(str2))
        return false;
    
    int arr[26]={0},len=strlen(str1);
    for(int i=0;i<len;i++)
    {
        if((str1[i]))
        arr[str1[i]-'a']++;
        arr[str2[i]-'a']--;
    }
        
       
    for(int i=0;i<26;i++)
        if(arr[i]!=0)
            return false;
    return true;

}
int main()
{

    char str1[100],str2[100];
    scanf("%s",str1);
    scanf("%s",str2);
    bool iret;
    iret=anagram(str1,str2);
    if(iret==true)
        printf("string is anagram\n");
    else
        printf("string is not anagram\n");
    return 0;
}