//wap in any high level language to inplement cohen sutherland line clipping algorithm
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#define TOP 8
#define BOTTOM 4
#define LEFT 1
#define RIGHT 2 

int x_min, y_min, x_max, y_max;
int computeCode(int x, int y) {
    int code = 0;
    if (y > y_max)       // above the clip window
        code |= TOP;
    else if (y < y_min)  // below the clip window
        code |= BOTTOM;
    if (x > x_max)       // to the right of clip window
        code |= RIGHT;
    else if (x < x_min)  // to the left of clip window
        code |= LEFT;
    return code;
}

void cohenSutherlandClip(int x0, int y0, int x1, int y1) {
    int code0 = computeCode(x0, y0);
    int code1 = computeCode(x1, y1);
    int accept = 0;

    while (1) {
        if ((code0 == 0) && (code1 == 0)) {
            accept = 1;
            break;
        } else if (code0 & code1) {
            break;
        } else {
            int code_out;
            int x, y;

            if (code0 != 0)
                code_out = code0;
            else
                code_out = code1;

            if (code_out & TOP) {
                x = x0 + (x1 - x0) * (y_max - y0) / (y1 - y0);
                y = y_max;
            } else if (code_out & BOTTOM) {
                x = x0 + (x1 - x0) * (y_min - y0) / (y1 - y0);
                y = y_min;
            } else if (code_out & RIGHT) {
                y = y0 + (y1 - y0) * (x_max - x0) / (x1 - x0);
                x = x_max;
            } else if (code_out & LEFT) {
                y = y0 + (y1 - y0) * (x_min - x0) / (x1 - x0);
                x = x_min;
            }

            if (code_out == code0) {
                x0 = x;
                y0 = y;
                code0 = computeCode(x0, y0);
            } else {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            }
        }
    }
    if (accept) {
        line(x0, y0, x1, y1);
    }
}

int main() {
    
    int x0, y0, x1, y1;

    printf("Enter clipping window coordinates (x_min, y_min, x_max, y_max): ");
    scanf("%d %d %d %d", &x_min, &y_min, &x_max, &y_max);

    printf("Enter line endpoints (x0, y0, x1, y1): ");
    scanf("%d %d %d %d", &x0, &y0, &x1, &y1);

    int wnd =initwindow(700,700,"Cohen Sutherland Line Clipping Algorithm");

    rectangle(x_min, y_min, x_max, y_max);
    setcolor(RED);
    line(x0, y0, x1, y1);

    setcolor(GREEN);
    cohenSutherlandClip(x0, y0, x1, y1);

    getch();
    closegraph(wnd);
    return 0;
}