#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	pid_t pid;
	int status;
	pid = fork();

	if(pid<0){
		fprintf(stderr,"fork failed \n");
		return 1;
	}
	else if(pid==0){
		printf("Child process with pid is %d \n",getpid());
		execl("/bin/ls","ls",NULL);
		perror("execution failed ");
		_exit(1);
	}
	else{
		printf("Parent process is %d \n",getpid());
		waitpid(pid,&status,0);
		printf("Child process completed with pid %d \n",pid);
	}
	return 0;
}
