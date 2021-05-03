#include <stdio.h>

#define CANVAS_W 1024
#define CANVAS_H 768
#define VIEW_W 650
#define VIEW_H 618
#define VIEW_Y 150

void projectandview(int x, int y, int z, int *x_, int *y_) {
    printf("step 0: %d, %d, %d\r\n", x, y, z);
    *x_ = x * 10 / z;
    *y_ = y * 10 / z;
    printf("step 1: %d, %d\r\n", *x_, *y_);
    
    *x_ = *x_ * CANVAS_W / VIEW_W;
    *y_ = *y_ * CANVAS_H / VIEW_H;

    printf("step 2: %d, %d\r\n", *x_, *y_);
    
    *y_ = (VIEW_Y + VIEW_H) - *y_;
    *y_ += VIEW_Y;

    printf("step 3: %d, %d\r\n", *x_, *y_);
    *x_ = CANVAS_W / 2 + *x_;
    *y_ = CANVAS_H / 2 + *y_;

	printf("step 4: %d, %d\r\n", *x_, *y_);
    
}

int main(int argc, char** argv) {
  int x = 0, y = 0;
  projectandview(-150,70,10, &x, &y);
  projectandview(-150,70,123, &x, &y);

  return 0;
}
