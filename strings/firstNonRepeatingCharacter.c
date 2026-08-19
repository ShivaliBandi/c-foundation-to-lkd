#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
char nonRepeatingChar(const char *str)
{   
    int freq[256]={0};
    size_t len = strlen(str);

    for(int i=0;i<len;i++)
        freq[(unsigned char)str[i]]++;
    
    for(int i=0;i<len;i++)
    {
        if(freq[(unsigned char)str[i]]==1)
            return str[i];
    }
    return '\0';
}
int main()
{

    char str[100];
    scanf("%s",str);
    
    printf("First non repeating character is %c\n",nonRepeatingChar(str));
    return 0;
}