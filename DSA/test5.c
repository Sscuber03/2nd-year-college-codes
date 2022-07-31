#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/syscall.h>
#include<sys/wait.h>
int main(){
int p,rst;
p=fork();
if(p==0){
printf("Child process");
}
else {
printf("Parent process");
waitpid(p,&rst,0);
}
return 0;
}

