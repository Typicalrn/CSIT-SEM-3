#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

void DDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    int count = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xinc = dx / (float)count;
    float yinc = dy / (float)count;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= count; i++) {
        putpixel(round(x), round(y), WHITE);
        x += xinc;
        y += yinc;
        delay(50);
    }
}

int main() {
    int wnd = initwindow(800, 600, "DDA Line Drawing Algorithm");

    int x1, y1, x2, y2;
    printf("Enter starting point (x1 y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter ending point (x2 y2): ");
    scanf("%d %d", &x2, &y2);

    DDA(x1, y1, x2, y2);

    getch();
    closegraph(wnd);
    return 0;
}
