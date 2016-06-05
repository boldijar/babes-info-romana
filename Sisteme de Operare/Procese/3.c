//The main process creates a new subprocess C for the arguments found on positions i and i+1.
//The C subprocess will create two new subprocesses A0 
//(for argument i) and A1 (for argument i+1) that using one of the exec calls 
//will try to execute the associated argument.
//Using dup2 call the C subprocess will redirect the standard output of A0 to A1.
//Sample arguments: i: ls i+1: sort, i: last i+1: head

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
	int fd[2];

	pipe(fd);

	if (fork()==0) {
		// child used for the first command
		dup2(fd[1], 1);
		close(fd[0]);
		if (execlp(argv[1], argv[1], NULL) < 0) {
			printf("Exec failed for argument: %s\n", argv[1]);
		}
		exit(0);
	}
	else {
		if (fork()==0) {
		// child used for the second command
		dup2(fd[0], 0);
		close(fd[1]);
		if (execlp(argv[2], argv[2], NULL) < 0) {
			printf("Exec failed for argument: %s\n", argv[2]);
		}
		exit(0);
		}
	}

	close(fd[0]);
	close(fd[1]);

	wait(0);
	wait(0);
	return 0;
}