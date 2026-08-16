//Copy the contents of one file to another.

#include <stdio.h>
int main()
{
    FILE *src, *dest;
    char source[100], target[100];
    char ch;

    printf("Enter source file: ");
    scanf("%s", source);

    printf("Enter destination file: ");
    scanf("%s", target);

    src = fopen(source, "r");
    dest = fopen(target, "w");

    if (src == NULL || dest == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    while ((ch = fgetc(src)) != EOF)
        fputc(ch, dest);

    fclose(src);
    fclose(dest);

    printf("File copied successfully.\n");

    return 0;
}

