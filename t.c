#include<stdio.h>
#include<stdlib.h>
#include <termios.h>

main(int C,char**A){FILE*F=fopen(A[1],"r");int P=0;
system("/bin/stty raw");
struct termios t;
tcgetattr(0, &t);
t.c_lflag &= ~ECHO;
tcsetattr(0, TCSANOW, &t);
int _[99999] = {0};
int *i=_;
char c = getchar();
}
