#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>

#define WIDTH 640
#define HEIGHT 480
#define INF 1e9

float zbuffer[WIDTH][HEIGHT];

void initZBuffer() {
    int x, y;
    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            zbuffer[x][y] = INF;
        }
    }
}

void putPixelZ(int x, int y, float z, int color) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        if (z < zbuffer[x][y]) {
            zbuffer[x][y] = z;
            putpixel(x, y, color);
        }
    }
}

int pointInTriangle(int x, int y, int x1, int y1, int x2, int y2, int x3, int y3) {
    float A  = fabs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)) / 2.0);
    float A1 = fabs((x*(y2-y3) + x2*(y3-y) + x3*(y-y2)) / 2.0);
    float A2 = fabs((x1*(y-y3) + x*(y3-y1) + x3*(y1-y)) / 2.0);
    float A3 = fabs((x1*(y2-y) + x2*(y-y1) + x*(y1-y2)) / 2.0);

    return (fabs(A - (A1 + A2 + A3)) < 1.0);
}

void drawTriangleZ(int x1, int y1, int x2, int y2, int x3, int y3, float z, int color) {
    int xmin, xmax, ymin, ymax;
    int x, y;

    xmin = x1;
    if (x2 < xmin) xmin = x2;
    if (x3 < xmin) xmin = x3;

    xmax = x1;
    if (x2 > xmax) xmax = x2;
    if (x3 > xmax) xmax = x3;

    ymin = y1;
    if (y2 < ymin) ymin = y2;
    if (y3 < ymin) ymin = y3;

    ymax = y1;
    if (y2 > ymax) ymax = y2;
    if (y3 > ymax) ymax = y3;

    for (x = xmin; x <= xmax; x++) {
        for (y = ymin; y <= ymax; y++) {
            if (pointInTriangle(x, y, x1, y1, x2, y2, x3, y3)) {
                putPixelZ(x, y, z, color);
            }
        }
    }
}

int main() {
    int wnd=initwindow(WIDTH, HEIGHT, "Z-Buffer Algorithm Demo");
    char msg1[] = "Z-Buffer Algorithm Demo";
    char msg2[] = "Green triangle is nearer than red triangle";
    
    initZBuffer();
    cleardevice();

    drawTriangleZ(200, 100, 100, 300, 300, 300, 0.8, RED);
    drawTriangleZ(250, 150, 150, 350, 350, 350, 0.3, GREEN);

    outtextxy(10, 10, msg1);
    outtextxy(10, 30, msg2);

    getch();
    closegraph(wnd);
    return 0;
}