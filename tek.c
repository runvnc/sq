int printf(char * s);
int getchar();
int sleep(int);

void tektronixMode() {
   printf("\x1b[?38h"); 
}

void clear() {
    printf("\x1b\xC");
}
void exitTechtronixMode() {
   printf("\x1b[?38l");  
}

void solid() {
    printf("\x1be");
}

int rightShift5(int n) {
    return (((((n/2)/2)/2)/2)/2);
}

int and(int a, int b) {
    int c = 0;
    for (int x = 0; x <= 15; ++x) {
        c += c;
        if (a < 0) {
            if (b < 0) {
                c += 1;
            }
        }
        a += a;
        b += b;
    }
    return c;
}

void coords(int x, int y) {
    printf("%c", rightShift5(y) + 32);
    printf("%c", and(y, 31) + 96);
    printf("%c", rightShift5(x) + 32);
    printf("%c", and(x, 31) + 64);
}

void graph() {
    printf("\x1d");
}


int main() {
   exitTechtronixMode();
   tektronixMode();
   tektronixMode();
   clear();
   solid();
   printf("   \n");
   printf("   \n");
   while (!getchar())
     sleep(100);

   //printf("Testing\n");
   graph();
   coords(100,100);
   coords(200,200);
   for (int y=0; y < 500; y += 10) {
     coords(30,y);
     coords(500,y);
   }
   printf("OK\r\n");
   sleep(50);
   clear();   
   graph();
   coords(100,100);
   coords(200,200);
   for (int y=0; y < 500; y += 10) {
     coords(60,y);
     coords(560,y);
     int d = getchar();
     printf("\n");
   }
   printf(" \n");
   sleep(50);
   while (!getchar())
     sleep(100);

   for (int n=0; n<10; n++)
     int l = getchar();
   while (!getchar())
     sleep(100);
   while (!getchar())
     sleep(100);
   while (!getchar())
     sleep(100);
   while (!getchar())
     sleep(100);

   //clear();
   //clear();     
   //exitTechtronixMode();
   //exitTechtronixMode();
   //printf("         *************************      \n");
}

