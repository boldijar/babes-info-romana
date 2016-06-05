#include <stdio.h>
#include <string.h>

int main() {
  char s[100];

  while(1) {
    scanf("%s", s);
    if(strcmp(s, "gata") == 0) {
      break;
    }
  }

  printf(":-)\n");

  return 0;
}
