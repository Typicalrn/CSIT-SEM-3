/* Program: Write a program to demonstrate 3D Transformations:
Translation, Rotation and Scaling.
*/
#include <graphics.h>
#include <process.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <dos.h>
#define x 250
#define y 100
#define z 100
int ori[24];
void wtor(int pts3[24]);
void cube(int pts1[16]);
void main()
{
int gd = DETECT, gm, s, ch;
void tran();
void rot();
void scale();
int wnd=initwindow(700,700, "  3d transformation");
printf("\n\t\t 3D TRANSFORMATION");
printf("\n ***********************");
printf("\n enter the side of the cube: ");
scanf("%d", &s);
ori[0] = x;
ori[1] = y;
ori[2] = z;
ori[3] = x + s;
ori[4] = y;
ori[5] = z;
ori[6] = x + s;
ori[7] = y;
ori[8] = z + s;
ori[9] = x;
ori[10] = y;
ori[11] = z + s;
ori[12] = x;
ori[13] = y - s;
ori[14] = z;
ori[15] = x + s;
ori[16] = y - s;
ori[17] = z;
ori[18] = x + s;
ori[19] = y - s;
ori[20] = z + s;
ori[21] = x;
ori[22] = y - s;
ori[23] = z + s;
wtor(ori);
getch();
do
{
clearviewport();
gotoxy(35, 5);
printf("\n 3d transformation\n");
printf("\n 1.translation\n");
printf("\n 2.rotation\n");
printf("\n 3.scaling\n");
printf("\n 4.exit");
printf("\n Enter ur choice: ");
scanf("%d", &ch);
printf("\n");
switch (ch)
{
case 1:
wtor(ori);
tran();
getch();
break;
case 2:
wtor(ori);
rot();
getch();
break;
case 3:
wtor(ori);
scale();
getch();
break;
case 4:
break;
default:
printf("\n invalid entry!!!");
getch();
break;
}
} while (ch != 4);
closegraph(wnd);
}
void cube(int pts1[16])
{
setcolor(15);
setlinestyle(DOTTED_LINE, 1, 1);
line(pts1[0], pts1[1], pts1[2], pts1[3]);
delay(100);
line(pts1[2], pts1[3], pts1[4], pts1[5]);
delay(100);
line(pts1[2], pts1[3], pts1[10], pts1[11]);
delay(100);
setlinestyle(SOLID_LINE, 1, 1);
line(pts1[4], pts1[5], pts1[6], pts1[7]);
delay(100);
line(pts1[6], pts1[7], pts1[0], pts1[1]);
delay(100);
line(pts1[0], pts1[1], pts1[8], pts1[9]);
delay(100);
line(pts1[4], pts1[5], pts1[12], pts1[13]);
delay(100);
line(pts1[6], pts1[7], pts1[14], pts1[15]);
delay(100);
line(pts1[8], pts1[9], pts1[10], pts1[11]);
delay(100);
line(pts1[10], pts1[11], pts1[12], pts1[13]);
delay(100);
line(pts1[12], pts1[13], pts1[14], pts1[15]);
delay(100);
line(pts1[8], pts1[9], pts1[14], pts1[15]);
delay(100);
setcolor(15);
}
void wtor(int pts3[24])
{
int pts2[16], i, j;
float a1 = 3.14 * 60 / 180;
float a2 = 3.14 * 60 / 180;
for (i = 0, j = 0; i < 24, j < 16; i += 3, j += 2)
{
pts2[j] = pts3[i] + pts3[i + 2] * 1 / tan(a1) * cos(a2);
pts2[j + 1] = pts3[i + 1] + pts3[i + 2] * 1 / tan(a1) *
cos(a2);
}
cube(pts2);
}
void tran()
{
int tr3[24];
int i, tx, ty, tz;
printf("\n enter the translation vectors: ");
scanf("%d%d%d", &tx, &ty, &tz);
for (i = 0; i < 24; i += 3)
{
tr3[i] = ori[i] + tx;
tr3[i + 1] = ori[i + 1] + ty;
tr3[i + 2] = ori[i + 2] + tz;
}
wtor(tr3);
}
void rot()
{
int r3[24];
float deg, rad;
int i, axis;
printf("\nenter the angle: ");
scanf("%f", &deg);
rad = 3.14 * deg / 180;
printf("\nchoose: x=1, y=2 or z=3: ");
scanf("%d", &axis);
for (i = 0; i < 24; i += 3)
{
switch (axis)
{
case 1:
r3[i] = ori[i];
r3[i + 1] = ori[i + 1] * cos(rad) - ori[i + 2] *
sin(rad);
r3[i + 2] = ori[i + 1] * sin(rad) + ori[i + 2] *
cos(rad);
break;
case 2:
r3[i + 1] = ori[i + 1];
r3[i] = ori[i + 2] * sin(rad) + ori[i] * cos(rad);
r3[i + 2] = ori[i + 2] * cos(rad) - ori[i] * sin(rad);
break;
case 3:
r3[i] = ori[i] * cos(rad) - ori[i + 1] * sin(rad);
r3[i + 1] = ori[i] * sin(rad) + ori[i + 1] * cos(rad);
r3[i + 2] = ori[i + 2];
break;
default:
printf("\ninvalid choice!!!");
getch();
break;
}
}
wtor(r3);
}
void scale()
{
float sx, sy, sz;
int i, s3[24];
printf("\nEnter the scaling factor: ");
scanf("%f %f %f", &sx, &sy, &sz);
for (i = 0; i < 24; i += 3)
{
s3[i] = ori[i] * sx;
s3[i + 1] = ori[i + 1] * sy;
s3[i + 2] = ori[i + 2] * sz;
}
wtor(s3);
}