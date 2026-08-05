//Aim- Delete a file.

#include <stdio.h>

int main()
{
    char filename[100];

    printf("Enter filename to delete: ");
    scanf("%s", filename);

    if (remove(filename) == 0)
        printf("File deleted successfully.\n");
    else
        printf("Unable to delete file.\n");

    return 0;
}

