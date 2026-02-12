/*WAP to implement  mid point circle algorithm assuming that the circle center is (xr,yr) 
clockwise direction [start position: (0,r)]
anticlockwise direction [start position: (r,0)]*/

#include <stdio.h>
#include <graphics.h>
#include <math.h>

void drawCircleClockwise(int xr, int yr, int r) {
    int x = 0, y = r;
    int d = 3 - 2 * r;
    
    while (x <= y) {
        delay(50);
        putpixel(xr + x, yr - y, WHITE);
        putpixel(xr + y, yr - x, WHITE);
        putpixel(xr + y, yr + x, WHITE);
        putpixel(xr + x, yr + y, WHITE);
        putpixel(xr - x, yr + y, WHITE);
        putpixel(xr - y, yr + x, WHITE);
        putpixel(xr - y, yr - x, WHITE);
        putpixel(xr - x, yr - y, WHITE);
        
        if (d < 0) {
            d = d + 4 * x + 6;
        } else {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

void drawCircleAntiClockwise(int xr, int yr, int r) {
    int x = r, y = 0;
    int d = 3 - 2 * r;
    
    while (x >= y) {
        delay(50);
        putpixel(xr + x, yr - y, WHITE);
        putpixel(xr + y, yr - x, WHITE);
        putpixel(xr + y, yr + x, WHITE);
        putpixel(xr + x, yr + y, WHITE);
        putpixel(xr - x, yr + y, WHITE);
        putpixel(xr - y, yr + x, WHITE);
        putpixel(xr - y, yr - x, WHITE);
        putpixel(xr - x, yr - y, WHITE);
        
        if (d < 0) {
            d = d + 4 * y + 6;
        } else {
            d = d + 4 * (y - x) + 10;
            x--;
        }
        y++;
    }
}

int main() {
    int wnd= initwindow(800, 600, "Mid Point Circle Algorithm - Clockwise and Anticlockwise");
    
    int xr, yr, r;
    printf("Enter the center of the circle (xr yr): ");
    scanf("%d %d", &xr, &yr);
    printf("Enter the radius of the circle: ");
    scanf("%d", &r);
    
    drawCircleClockwise(xr, yr, r);
    drawCircleAntiClockwise(xr + 250, yr, r);
    
    getch();
    closegraph(wnd);
    return 0;
}