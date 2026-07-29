#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

#define BUFFER_SIZE 100

int main(){
    int fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

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