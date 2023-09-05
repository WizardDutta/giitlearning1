#include<stdio.h>


int main()
{
    FILE* fptr = fopen("file.txt","w");
    printf("I am a good boy");
    char ch;
    ch = getc(stdout);
    while(ch!=EOF)
    {
        fprintf(fptr,"%c",ch);
        ch = getc(stdout);
    }
    fclose(fptr);
    return 0;
}