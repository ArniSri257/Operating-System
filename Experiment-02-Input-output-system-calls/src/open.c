#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
    int fd;
    fd= open("sample.txt",O_CREAT | O_WRONLY, 0644);
    if(fd == -1){
        printf("Error opening filr\n");
        return 1;
    } 
    printf("File opened successfully. \n");
    close(fd);
    return 0;
} 