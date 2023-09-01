#include<stdio.h>
#include<stdlib.h>


void printFile(char* s)
{
    FILE* fp = fopen(s,"r");
    if(!fp)
    {
        printf("%s does not exist\n",s);
        return;
    }
    char ch;
    ch = getc(fp);
    while (ch!=EOF)
    {
        printf("%c",ch);
        ch = getc(fp);
    }
    fclose(fp);
}
void copyFile()
{
    char f1[20],f2[20];
    printf("Enter name of file to copy from\n-> ");
    scanf("%s",f1);
    printf("Enter name of second file to write into\n-> ");
    scanf("%s",f2);
    FILE *fp1,*fp2;
    fp1 = fopen(f1,"r");
    if(!fp1)
    {
        printf("%s does not exist\n",f1);
        return;
    }
    fp2 = fopen(f2,"w");
    char ch;
    ch = getc(fp1);
    while (ch!=EOF)
    {
        fprintf(fp2,"%c",ch);
        ch = getc(fp1);
    }
    fclose(fp1);
    fclose(fp2);
}
void mergeFile()
{
    char f1[20],f2[20],f3[20];
    printf("Enter the first file to merge\n-> ");
    scanf("%s",f1);
    printf("Enter the second file to merge\n-> ");
    scanf("%s",f2);
    printf("Enter file name to merge into\n-> ");
    scanf("%s",f3);
    FILE *fp1,*fp2,*fp3;
    fp1 = fopen(f1,"r");
    if(!fp1)
    {
        printf("%s does not exist\n",f1);
        return;
    }
    fp3 = fopen(f3,"w");
    char ch;
    // reading from first file
    ch = getc(fp1);
    while (ch!=EOF)
    {
        fprintf(fp3,"%c",ch);
        ch = getc(fp1);
    }
    fclose(fp1); //first file closed
    fp2 = fopen(f2,"r");
    if(!fp2)
    {
        printf("%s does not exist\n",f2);
        return;
    }
    //reading from second file
    ch = getc(fp2);
    while (ch!=EOF)
    {
        fprintf(fp3,"%c",ch);
        ch = getc(fp2);
    }
    fclose(fp2);
    fclose(fp3);
}
void deleteFile()
{
    char file[20];
    printf("Enter name of the file to be deleted\n-> ");
    scanf("%s",file);
    if(remove(file))
        printf("Error Occured! file deletion Unsuccessful!\n");
    else
        printf("Successfully deleted\n");
}
void menu()
{
    int x;
    char file_name[50];
    while(1)
    {
        printf("\n\n\n");
        printf("1.  Print the contents of file\n");
        printf("2.  Copy contents of one file to another file\n");
        printf("3.  Merge contents of two file into a third file\n");
        printf("4.  Delete a File\n");
        printf("5. To quit\n-> ");
        scanf("%d",&x);
        switch (x)
        {
            case 1:
                printf("Enter File name\n-> ");
                scanf("%s",file_name);
                printFile(file_name);
                break;
            case 2: 
                copyFile();
                break;
            case 3:
                mergeFile();
                break;
            case 4:
                deleteFile();
                break;
            case 5:
                exit(0);
        }
    }
}
int main()
{
    menu();
    return 0;
}