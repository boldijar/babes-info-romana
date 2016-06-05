#include <stdio.h>

int main(void) {
	FILE *in;
	extern FILE *popen();
	char buff[512];

	if(!(in = popen("ls -sail", "r"))){
		exit(1);
	}

	while(fgets(buff, sizeof(buff), in)!=NULL){
		printf("%s", buff);
	}
	pclose(in);

}
