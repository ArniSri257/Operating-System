<<<<<<< HEAD
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

#define BUFFER_SIZE 100

int main(){
=======
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 100

int main()
{
>>>>>>> b7dec27 (Added Program 2)
    int fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

<<<<<<< HEAD
    //open the file in readonly mode
    fd=open("sample.txt", O_RDONLY);

    if(fd == -1){
        printf("Error opening file. \n");
        return 1;
    }
    // read data from file
    bytesRead=read(fd,buffer,BUFFER_SIZE-1);
    if (bytesRead == -1){
        printf("Error reading file. \n");
        close(fd);
        return 1;
    }
    //add null character to make it a string
    buffer[bytesRead]='\0';
    printf("File contents: \n");
    printf("%s",buffer);

    //close the file
    close(fd);
    return 0;
}
=======
    // Open the file in read-only mode
    fd = open("sample.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening file.\n");
        return 1;
    }
    // Read data from the file
    bytesRead = read(fd, buffer, BUFFER_SIZE - 1);
    if (bytesRead == -1)
    {
        printf("Error reading file.\n");
        close(fd);
        return 1;
    }
    // Add null character to make it a string
    buffer[bytesRead] = '\0';
    printf("File Contents:\n");
    printf("%s", buffer);
    // Close the file
    close(fd);
    return 0;
}
>>>>>>> b7dec27 (Added Program 2)
