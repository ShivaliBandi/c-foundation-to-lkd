#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100
int count(const char *str)
{
    int icnt=0,inword=0;
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]!=' ' && inword==0)
        {
            inword=1;
            icnt++;
        }
        else if(str[i]==' ')
        {
            inword=0;
        }
      
        
           
    }
    return icnt;
}
void tokenize(char str[])
{
   int icount=count(str);
   char **tokenStr=NULL;
   tokenStr=malloc((icount)*sizeof(char *));
   
   
   // Space is used as the delimiter to split
    char delimiter[] = " ";

    // Declare empty string to store token
    char *token;

    // Get the first token
    token = strtok(str, delimiter);
    if (token == NULL)
    {
        printf("no string found\n");
        return;
    }
    tokenStr[0]=malloc((strlen(token)+1)*sizeof(char));
    strcpy(tokenStr[0],token);
    int i=1;
    // Continue upto the last token
    while (token != NULL)
    {
        // Pass NULL to get next token

        token = strtok(NULL, delimiter);
        if(token==NULL)
            break;
        tokenStr[i]=malloc((strlen(token)+1)*sizeof(char));
        strcpy(tokenStr[i],token);
        i++;
    }
    for(int i=0;i<icount;i++)
        printf("%s\n",tokenStr[i]);
    char outputString[SIZE]="";
    for(int i=icount-1;i>=0;i--)
    {
        strcat(outputString, tokenStr[i]);
        strcat(outputString, " ");
    }
    printf("\n\n%s\n\n",outputString);


}
int main() {
    char sentence[SIZE]; // Array large enough to store the sentence

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = '\0';
    printf("count %d",count(sentence));

    // // fgets(array_name, maximum_size, stdin)
    // 
    // 
    // printf("You entered: %s", sentence);
    // tokenize(sentence); 
    return 0;
}
