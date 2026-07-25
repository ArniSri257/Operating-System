#include<stdio.h>
#include<dirent.h>
int main(){
    DIR *dir;
    dir=opendir(".");
    if (dir){
        printf("Directory opened successfully\n");
        closedir(dir);
    }
    return 0;
}