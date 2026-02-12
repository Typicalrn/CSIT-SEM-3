#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>


//line 1
int a1=300;
int b1=100;

// line 2
int c1 = 200;
int d1 = 300;

// line3
int e1 = 400;
int f1 = 300;

//scaling points
int sx = 2, sy = 2;

//fixed points
int xf = 300, yf = 300;

int result[3][3];

//scaling matrix
int scaling_matrix[3][3] = {
{sx, 0, xf*(1-sx)},
{0, sy, yf*(1-sy)},
{0, 0, 1}
};

//original matrix
int original_matrix[3][3] = {
  {a1,c1,e1},
  {b1,d1,f1},
  {1,1,1}
};

void matrixmultiplication(int m1[3][3], int m2[3][3]){

   for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = 0;

            for (int k = 0; k < 3; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }

            printf("%d\t", result[i][j],i,j);
        }

        printf("\n");
    }
}

void scaling2D(){

  matrixmultiplication(scaling_matrix, original_matrix);

  int newX1 = round(result[0][0]);
  int newY1 = round(result[1][0]);

  int newX2 = round(result[0][1]);
  int newY2 = round(result[1][1]);

  int newX3 = round(result[0][2]);
  int newY3 = round(result[1][2]);

  int xmin = newX1;
  int ymin = newY1;

  if(newX2 < xmin){ xmin = newX2;}
  if(newX3 < xmin){ xmin = newX3;}

  if(newY2 < ymin){ ymin = newY2;}
  if(newY3 < ymin){ ymin = newY3;}

  int tx = (xmin < 0) ? -xmin : 0;
  int ty = (ymin < 0) ? -ymin : 0;

  line(newX3 + tx, newY3 + ty, newX1 + tx, newY1 + ty);
  line(newX1 + tx, newY1 + ty, newX2 + tx, newY2 + ty);
  line(newX2 + tx, newY2 + ty, newX3 + tx, newY3 + ty);


}

int main(){

  initwindow(700,700,"2D Scaling");

  line(a1,b1,c1,d1);
  line(c1,d1,e1,f1);
  line(e1,f1,a1,b1);

  scaling2D();

  getch();
  closegraph();
  
  return 0;
}
