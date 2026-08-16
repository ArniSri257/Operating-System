//Create a new directory.

#include <stdio.h>
#include <sys/stat.h>

int main()
{
    char dirname[100];

    printf("Enter directory name: ");
    scanf("%s", dirname);

    if (mkdir(dirname, 0777) == 0)
        printf("Directory created successfully.\n");
    else
        printf("Directory already exists or cannot be created.\n");

    return 0;
}
