#include<stdio.h>
#include<stdlib.h>
#include<termios.h>
main(int C,char**A){FILE*F=fopen(A[1],"r");int P=0;
system("/bin/stty raw");
struct termios t;
tcgetattr(0, &t);
t.c_lflag &= ~ECHO;
tcsetattr(0, TCSANOW, &t);
int _[99999];
int *i=_;while(fscanf(F,
"%d",i++)>0);while(P>=0){int a=_[P++],b=_[P++],c=_[P++];a<0?_[b]+=getchar():b<0
?printf("%c",_[a]):(_[b]-=_[a])<=0?P=c:0;}}
