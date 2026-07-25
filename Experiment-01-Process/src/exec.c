#include<stdio.h>
#include<unistd.h>
int main(){
    execl("/bin/ls","ls","-1",NULL);
    printf("This line will not execute.");
    return 0;
}