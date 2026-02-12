#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>

int main()
{
    int x1, y1, x2, y2;
    int dx, dy, p;
    int x, y;

    int wnd=initwindow(800, 600, "Bresenham's Line Drawing Algorithm");

    printf("Enter starting point (x1 y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter ending point (x2 y2): ");
    scanf("%d %d", &x2, &y2);

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    x = x1;
    y = y1;

    putpixel(x, y, WHITE);

    /* Case 1: Slope <= 1 */
    if (dx >= dy)
    {
        p = 2 * dy - dx;

        while (x != x2)
        {
            x += (x2 > x1) ? 1 : -1;

            if (p < 0)
            {
                p = p + 2 * dy;
            }
            else
            {
                y += (y2 > y1) ? 1 : -1;
                p = p + 2 * (dy - dx);
            }

            putpixel(x, y, WHITE);
        }
    }
    /* Case 2: Slope > 1 */
    else
    {
        p = 2 * dx - dy;

        while (y != y2)
        {
            y += (y2 > y1) ? 1 : -1;

            if (p < 0)
            {
                p = p + 2 * dx;
            }
            else
            {
                x += (x2 > x1) ? 1 : -1;
                p = p + 2 * (dx - dy);
            }

            putpixel(x, y, WHITE);
        }
    }

    getch();
    closegraph(wnd);
    return 0;
}
