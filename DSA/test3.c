#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
char *arg[]={"/bin/ls","-l",NULL};
printf("Hi\n");
execv(arg[0], arg);
printf("Hi\n");
return 0;
}
