#include<stdio.h>
#include<string.h>
#define maxfile 100
#define maxnamelength 20

typedef struct{
	char name[maxnamelength];
	int parentindex;
}file;

void singleleveldirectory(){
	file files[maxfile];
	int filecount=0;
	strcpy(files[filecount].name,"file1.txt");
	files[filecount++].parentindex=-1;

	strcpy(files[filecount].name,"file2.txt");
        files[filecount++].parentindex=-1;
	
	printf("Files in directory \n");
	for(int i=0;i<filecount;i++){
		printf("%s \n",files[i].name);
	}
}

void twoleveldirectory(){
        file files[maxfile];
        int filecount=0;
        strcpy(files[filecount].name,"file1.txt");
        files[filecount++].parentindex=0;

        strcpy(files[filecount].name,"file2.txt");
        files[filecount++].parentindex=0;
	
	strcpy(files[filecount].name,"file1.txt");
        files[filecount++].parentindex=1;

        printf("Files in directory 1\n");
        for(int i=0;i<filecount;i++){
        	if(files[i].parentindex==0){
                printf("%s \n",files[i].name);
}
	
	}

	printf("Files in directory 2\n");
        for(int i=0;i<filecount;i++){
        if(files[i].parentindex==1){
                printf("%s \n",files[i].name);
        }
	}
}


int main(){
	printf("simulating single level directory \n");
	singleleveldirectory();
	printf("simulating two level directory \n");
	twoleveldirectory();

	return 0;
}





