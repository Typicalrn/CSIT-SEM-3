#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define STEPS 1000
#define REPEATS 1000
#define STEP_SIZE 5

int main() {
    int i, j;
    double avg_disp = 0.0;

    srand(time(NULL));

    /* ---------- CREATE GRAPHICS WINDOW ---------- */
    int wnd=initwindow(800, 600, "2D Random Walk Simulation");

    int x = 400;
    int y = 300;
    int startX = x, startY = y;

    /* Mark starting point */
    setcolor(GREEN);
    circle(x, y, 4);
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(x, y, GREEN);

    setcolor(WHITE);

    /* ---------- SHOW WALKING PROCEDURE ---------- */
    for (i = 0; i < STEPS; i++) {
        int dir = rand() % 4;
        int newX = x;
        int newY = y;

        if (dir == 0) newX += STEP_SIZE;      // Right
        else if (dir == 1) newX -= STEP_SIZE; // Left
        else if (dir == 2) newY -= STEP_SIZE; // Up
        else newY += STEP_SIZE;               // Down

        line(x, y, newX, newY);
        x = newX;
        y = newY;

        delay(10);
    }

    /* Mark final point */
    setcolor(RED);
    circle(x, y, 4);
    setfillstyle(SOLID_FILL, RED);
    floodfill(x, y, RED);

    /* ---------- CALCULATE AVERAGE DISPLACEMENT ---------- */
    for (i = 0; i < REPEATS; i++) {
        int rx = 0, ry = 0;
        for (j = 0; j < STEPS; j++) {
            int dir = rand() % 4;
            if (dir == 0) rx++;
            else if (dir == 1) rx--;
            else if (dir == 2) ry++;
            else ry--;
        }
        avg_disp += sqrt(rx * rx + ry * ry);
    }

    avg_disp /= REPEATS;

    /* ---------- DISPLAY TEXT ---------- */
    setcolor(YELLOW);
    char startText[] = "Green: Start";
    char endText[]   = "Red: End";

    outtextxy(10, 10, startText);
    outtextxy(10, 30, endText);


    char result[100];
    sprintf(result, "Average Displacement = %.2f", avg_disp);
    outtextxy(10, 50, result);

    getch();
    closegraph(wnd);
    return 0;
}
