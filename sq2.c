#include<stdio.h>
#include<stdlib.h>
#include<termios.h>
#include<unistd.h>
#include<sys/ioctl.h>

int kbhit() {
   int count = 0;
   struct termios otty, ntty;
   tcgetattr(STDIN_FILENO, &otty);
   ntty = otty;
   ntty.c_lflag &= ~ICANON;
   if(tcsetattr(STDIN_FILENO, TCSANOW, &ntty) == 0) {
      ioctl(STDIN_FILENO, FIONREAD, &count);
      tcsetattr(STDIN_FILENO, TCSANOW, &otty);
   }
   return count;
}

int main(int C,char**A) {
  FILE *F = fopen(A[1],"r");
  int P=0;
  system("/bin/stty raw");
  struct termios t;
  tcgetattr(0, &t);
  t.c_lflag &= ~ECHO;
  tcsetattr(0, TCSANOW, &t);
  int _[99999];
  int *i=_;while(fscanf(F,
  "%d",i++)>0);while(P>=0){int a=_[P++],b=_[P++],c=_[P++];a==-1?_[b]+=kbhit():b==-1
  ?printf("%c",_[a]):b==-16?usleep(_[a]*1000):(_[b]-=_[a])<=0?P=c:0;}
}
