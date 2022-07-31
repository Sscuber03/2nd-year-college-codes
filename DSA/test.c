#include<stdio.h>
#include<unistd.h>
#include<sys/syscall.h>
#include<sys/types.h>
int main(){
unsigned cpu, node;
syscall(SYS_getcpu, &cpu, &node, NULL);
printf("%u %u \n", cpu, node);
return 0;
}

