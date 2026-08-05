#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(){
    int fd;
    char message[]= "Hello!\n Welcome to Linux System calls.\n This file is created using write() system call.\n";

    //open or create the file
    fd= open ("output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fd == -1){
        printf("Error opening file. \n");
        return 1;
    }
    // write data to the file
    if (write(fd,message,strlen(message)) == -1){
        printf("Error writing to file. \n");
        close(fd);
        return 1;

    } printf("Data written successfully to output.txt \n");

    //close the file
    close(fd);

    return 0;
}