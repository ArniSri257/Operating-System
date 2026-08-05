//Write a C program to display the files and directories present in the current directory (similar to the ls command).
//Displays all files and directories in the current directory.

#include <stdio.h>
#include <dirent.h>

int main()
{
    struct dirent *d;
    DIR *dir = opendir(".");

    if (dir == NULL)
    {
        printf("Unable to open directory.\n");
        return 1;
    }

    printf("Files and Directories:\n");

    while ((d = readdir(dir)) != NULL)
    {
        printf("%s\n", d->d_name);
    }

    closedir(dir);
    return 0;
}
