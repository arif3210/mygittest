#include<stdio.h>
#include <sys/types.h>
#include<stdlib.h>  
#include<unistd.h>
void main(){
    if(fork()){
    printf("hi");
    }
}