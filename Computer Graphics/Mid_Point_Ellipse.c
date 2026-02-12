    // WAP using graphics to implement Mid Point Ellipse Algorithm

    #include <stdio.h>
    #include <graphics.h>
    #include <math.h>

    /* Plot 4-way symmetric points */
    void plot(int xc, int yc, int x, int y){
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
    }

    /* REGION 1 */
    void region1(int xc, int yc, int a, int b, int *x, int *y){
        float d1, dx, dy;

        *x = 0;
        *y = b;

        dx = 2 * b * b * (*x);
        dy = 2 * a * a * (*y);

        d1 = (b * b) - (a * a * b) + (0.25 * a * a);

        while (dx < dy){
            delay(50);
            plot(xc, yc, *x, *y);

            if (d1 < 0){
                (*x)++;
                dx = dx + (2 * b * b);
                d1 = d1 + dx + (b * b);
            }
            else
            {
                (*x)++;
                (*y)--;
                dx = dx + (2 * b * b);
                dy = dy - (2 * a * a);
                d1 = d1 + dx - dy + (b * b);
            }
        }
    }

    /* REGION 2 */
    void region2(int xc, int yc, int a, int b, int x, int y){
        float d2, dx, dy;

        dx = 2 * b * b * x;
        dy = 2 * a * a * y;

        d2 = (b * b * (x + 0.5) * (x + 0.5)) +
            (a * a * (y - 1) * (y - 1)) -
            (a * a * b * b);

        while (y >= 0)
        {
            delay(50);
            plot(xc, yc, x, y);

            if (d2 > 0)
            {
                y--;
                dy = dy - (2 * a * a);
                d2 = d2 + (a * a) - dy;
            }
            else
            {
                y--;
                x++;
                dx = dx + (2 * b * b);
                dy = dy - (2 * a * a);
                d2 = d2 + dx - dy + (a * a);
            }
        }
    }

    int main(){
        int wnd = initwindow(800, 600, "Mid Point Ellipse Algorithm");
        int xc, yc, a, b;
        int x, y;

        printf("Enter center of ellipse (xc yc): ");
        scanf("%d %d", &xc, &yc);

        printf("Enter semi-major and semi-minor axes (a b): ");
        scanf("%d %d", &a, &b);

        region1(xc, yc, a, b, &x, &y);   // Region 1
        region2(xc, yc, a, b, x, y);     // Region 2 continues

        getch();
        closegraph(wnd);
        return 0;
    }
