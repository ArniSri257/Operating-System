//Write a C program to display the files and directories present in the current directory (similar to the ls command).
//Displays all files and directories in the current directory.

#include <stdio.h>
#include <string.h>

int main()

{
    FILE *fp;
    char filename[100], word[50], line[200];

    printf("Enter filename: ");
    scanf("%s", filename);

    printf("Enter word to search: ");
    scanf("%s", word);

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("File not found.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp))
    {
        if (strstr(line, word))
        {
            printf("%s", line);
        }
    }

    fclose(fp);
    return 0;
}

