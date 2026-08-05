//Display the current working directory.
#include <stdio.h>
#include <unistd.h>

int main()
{
    char cwd[1024];

    if (getcwd(cwd, sizeof(cwd)) != NULL)
        printf("Current Directory: %s\n", cwd);
    else
        printf("Error!\n");

    return 0;
}
