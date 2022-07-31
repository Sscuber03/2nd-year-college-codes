#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
pid_t p,p2;
p2=fork();
p=fork();
printf("Hi CSE");
return 0;
}
