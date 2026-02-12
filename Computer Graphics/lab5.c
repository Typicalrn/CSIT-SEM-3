//wap to draw a polygon of your own size and perform 2d translation, 2d rotation, 2d scaling.
#include <stdio.h>
#include <graphics.h>
#include <math.h>
#define MAX 10
#ifndef M_PI
#define M_PI 3.14159265358979323846 
#endif

void draw_polygon(int x[], int y[], int n) {
    for (int i = 0; i < n; i++) {
        line(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
    }
}
void translate(int x[], int y[], int n, int tx, int ty) {
    for (int i = 0; i < n; i++) {
        x[i] += tx;
        y[i] += ty;
    }
}
void rotate(int x[], int y[], int n, float angle) {
    float rad = angle * M_PI / 180.0;
    for (int i = 0; i < n; i++) {
        int x_new = x[i] * cos(rad) - y[i] * sin(rad);
        int y_new = x[i] * sin(rad) + y[i] * cos(rad);
        x[i] = x_new;
        y[i] = y_new;
    }
}
void scale(int x[], int y[], int n, float sx, float sy) {
    for (int i = 0; i < n; i++) {
        x[i] = x[i] * sx;
        y[i] = y[i] * sy;
    }
}
int main() {
    int wnd=initwindow(500, 800,"2D Transformations");

    int n, x[MAX], y[MAX];
    printf("Enter number of vertices of the polygon (max %d): ", MAX);
    scanf("%d", &n);
    printf("Enter the coordinates of the polygon:\n");
    for (int i = 0; i < n; i++) {
        printf("Vertex %d (x y): ", i + 1);
        scanf("%d %d", &x[i], &y[i]);
    }

    // Draw original polygon
    setcolor(WHITE);
    draw_polygon(x, y, n);
    getch();

    // 2D Translation
    int tx, ty;
    printf("Enter translation values (tx ty): ");
    scanf("%d %d", &tx, &ty);
    translate(x, y, n, tx, ty);
    cleardevice();
    setcolor(GREEN);
    draw_polygon(x, y, n);
    getch();

    // 2D Rotation
    float angle;
    printf("Enter rotation angle (in degrees): ");
    scanf("%f", &angle);
    rotate(x, y, n, angle);
    cleardevice();
    setcolor(BLUE);
    draw_polygon(x, y, n);
    getch();

    // 2D Scaling
    float sx, sy;
    printf("Enter scaling factors (sx sy): ");
    scanf("%f %f", &sx, &sy);
    scale(x, y, n, sx, sy);
    cleardevice();
    setcolor(RED);
    draw_polygon(x, y, n);
    getch();

    closegraph(wnd);
    return 0;
}