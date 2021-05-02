int printf(char * s);
int getchar();


// *************************** SUBLEQ bit operations ************************
int rightShift5(int n) {
    return (((((n/2)/2)/2)/2)/2);
}

int and(int a, int b) {
    int c = 0;
    for (int x = 0; x <= 15; ++x) {
        c += c;
        if (a < 0) {
            if (b < 0) { c += 1; }
        }
        a += a;
        b += b;
    }
    return c;
}
// ************************* End SUBLEQ bit operations *************************

// *************************** Tektronix control ***************************************
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

void coords(int x, int y) {
    printf("%c", rightShift5(y) + 32);
    printf("%c", and(y, 31) + 96);
    printf("%c", rightShift5(x) + 32);
    printf("%c", and(x, 31) + 64);
}

void graph() {
    printf("\x1d");
}
// ************************ End Techtronix control **************************

// ************************ 3D rendering ************************************
/* 
Say the camera's at (Xc, Yc, Zc) and the point you want to project is P = (X, Y, Z). The distance from the camera to the 2D plane onto which you are projecting is F (so the equation of the plane is Z-Zc=F). The 2D coordinates of P projected onto the plane are (X', Y').

Then, very simply:

X' = ((X - Xc) * (F/Z)) + Xc

Y' = ((Y - Yc) * (F/Z)) + Yc

If your camera is the origin, then this simplifies to:

X' = X * (F/Z)

Y' = Y * (F/Z) */

function rotate(pitch, roll, yaw) {
    var cosa = Math.cos(yaw);
    var sina = Math.sin(yaw);

    var cosb = Math.cos(pitch);
    var sinb = Math.sin(pitch);

    var cosc = Math.cos(roll);
    var sinc = Math.sin(roll);

    var Axx = cosa*cosb;
    var Axy = cosa*sinb*sinc - sina*cosc;
    var Axz = cosa*sinb*cosc + sina*sinc;

    var Ayx = sina*cosb;
    var Ayy = sina*sinb*sinc + cosa*cosc;
    var Ayz = sina*sinb*cosc - cosa*sinc;

    var Azx = -sinb;
    var Azy = cosb*sinc;
    var Azz = cosb*cosc;

    for (var i = 0; i < points.length; i++) {
        var px = points[i].x;
        var py = points[i].y;
        var pz = points[i].z;

        points[i].x = Axx*px + Axy*py + Axz*pz;
        points[i].y = Ayx*px + Ayy*py + Ayz*pz;
        points[i].z = Azx*px + Azy*py + Azz*pz;
    }
}

// ********************* End 3D rendering *******************************



int main() {
   exitTechtronixMode();
   tektronixMode();
   tektronixMode();
   clear();
   solid();
   printf("   \n");
   printf("   \n");
   graph();
   coords(500,0);
   coords(500,1000);
   printf("\r\n");
   getchar();
   clear();
   exitTechtronixMode();
   clear();
}

