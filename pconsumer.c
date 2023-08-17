#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int front = -1,rear = -1,mutex = 0,queue[SIZE],product = 1;
void enqueue(){
	if(mutex >= SIZE){
		printf("BUFFER IS FULL..\n");
		return;
	}else if(front == -1 && rear == -1 ){
		front = rear = 1;
		queue[front] = product;
		printf("PRODUCED %d\n",product);
		product++;
		mutex++;
		return;
	}else{
		if(rear == SIZE-1 && front > 1){
			rear = (rear % (SIZE-1)) + 1;
			queue[rear] = product;
			printf("PRODUCED %d\n",product);
			product++;
			mutex++;
			return;
		}else{
			queue[rear] = product;
			printf("PRODUCED %d\n",product);
			product++;
			mutex++;
			if(rear + 1 != front || rear -(SIZE -1) != front){
				rear++;
			}
			return;
		}
	}
}
void dequeue(){
	printf("hi");
}
void main(){
	int choice;
	while(1){
		printf("1.PRODUCE\n2.CONSUME\n3.EXIT\n");
		scanf("%d\n",&choice);
		switch(choice){
			case 1:
				enqueue();
				
				break;
			case 2:
				dequeue();
				break;
			case 3:exit(0);
			default:printf("NOT A VALID OPTION\n");
		}
	}
}