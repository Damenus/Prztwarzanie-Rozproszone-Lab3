#include <unistd.h>
#include <stdio.h>

//ps -u student --forest
//whoami

void loop(int a){

	int pid = fork();
	
	if (a == 0){
		sleep(15);
		return 0;
	} else if (pid == 0) {
		loop(a-1);
		sleep(3);
	}	
		
	//printf("%d\n",a);
	//execlp("ps", "-o pid,uname,comm", "-u student", "--forest", NULL);
//execlp("ps", "-u student", "--forest", NULL); 
}

int main(int argc, char *argv[]) {

	int main = getpid();
	int arg;

	for(int i = 1; i < argc; i++){
		arg = atoi(argv[i]) - 1;
		loop(arg);
		//loop(atoi(argv[i]));
	}

	if(getpid() == main)
		execlp("ps", "-o pid,uname,comm", "--forest", NULL); 


return 0;
}
