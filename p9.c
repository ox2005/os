#include<stdio.h>
#include<stdlib.h>
#define MAX_BLOCKS 100
struct block{
	int blocknumber;
	struct block*next;
};

void initialize(struct block*disk[],int size){
	for(int i=0;i<size;i++){
		disk[i]=NULL;
	}}
void displaydisk(struct block*disk[],int size){
	printf("Disk Blocks: \n");
	for(int i=0;i<size;i++){
		printf("Blokc %d: ",i);
		struct block*current = disk[i];
		while(current!=NULL){
			printf("%d ",current->blocknumber);
			current = current->next;
		}
		printf("NULL \n");
	}
}

int allocateblock(struct block*disk[],int size,int fileindex,int blocknumber){
	struct block *newblock=(struct block*)malloc(sizeof(struct block));
	if(newblock==NULL){
		printf("Memory allocation failed \n");
		return 0;
	}
	newblock->blocknumber = blocknumber;
	newblock->next = NULL;
	if(disk[fileindex]==NULL){
		disk[fileindex]=newblock;
	}else{
		struct block*current =disk[fileindex];
		while(current->next!=NULL){
			current = current->next;
		}
		current->next = newblock;
	}
	return 1;
}

int main(){
	struct block*disk[MAX_BLOCKS];
	int disksize = 10;
	initialize(disk,disksize);
	allocateblock(disk,disksize,0,1);
	allocateblock(disk,disksize,0,3);
	displaydisk(disk,disksize);
	return 0;
}
