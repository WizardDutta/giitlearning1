// C program to implement
// the above approach
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void reading()
{
	FILE* fptr;
	char ch;
	fptr = fopen("file.txt", "r");
	if (!fptr) 
    {
		printf("File not found \n");
        return;
	}
    printf("content in File: \n");
	while (ch != EOF)
    {
        ch = fgetc(fptr); //reades each character from file
		printf("%c", ch);
    }
	fclose(fptr);
}
void writing()
{
    FILE *fptr;
    fptr = fopen("file.txt","w");
    printf("Input : ");
    char ch = getchar();
    while(ch!=EOF) //writes into file one character at a time
    {
        fprintf(fptr,"%c",ch);
        ch = getchar();
    }
   fclose(fptr);
}
void strings_to_file()
{
    char str[500];
    printf("Enter the string you want to write\n");
    fgets(str,500,stdin);
    str[strlen(str)-1] = '\0';
    FILE* fptr = fopen("file.txt","w");
    fprintf(fptr,"%s",str);
    fclose(fptr);
}
void read_write_bs_file()
{
    FILE* fptr = fopen("file2.txt","wb");
    printf("write something: ");
    char ch;
    do
    {
        ch = getchar();
        fprintf(fptr,"%c",ch);
    } while (ch!=EOF);
    fclose(fptr);
    fptr = fopen("file2.txt","rb");
    do
    {
        ch = fgetc(fptr);
        printf("%c",ch);
    } while (ch!=EOF);
    fclose(fptr);
}
void menu()
{
    printf("1. Reading a File\n");
    printf("2. Writing a File\n");
    printf("3. Reading and writing strings to file\n");
    printf("4. Reading and writng binary files\n");
    int x;
    scanf("%d",&x);
    switch (x)
    {
        case 1:
            reading();
            break;
        case 2:
            writing();
            break;
        case 3:
            strings_to_file();
            break;
        case 4:
            read_write_bs_file();
            break;
        default:
            exit(0);
    }
}
int main()
{
   menu();
   return 0;
}
