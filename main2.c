#include <unistd.h>
#include <stdio.h>

void loop(int argc, char*argv[], int wsk){
	
	wsk = wsk + 1;
	if(wsk == argc) {
		sleep(15);
		return 0;
	} else {		
		int warunek = atoi(argv[wsk]);
		for(int i = 0; i < warunek; i++) {
			int pid = fork();
			if (pid == 0) {		 
				loop(argc, argv, wsk);
				sleep(15);
				return 0;
			}	
		}
	}
}

int main(int argc, char *argv[]) {

	int main = getpid();
	int wsk = 0; //od 1 bo na argv[0] jest nazwa programu, ale jednak 0 bo rekurencja go zwiększa; wskaźnik na ktory parametr patrzy
	
	loop(argc, argv, wsk);		

	if(getpid() == main)
		execlp("ps", "-u student", "--forest",NULL); //-o

	return 0;
}
