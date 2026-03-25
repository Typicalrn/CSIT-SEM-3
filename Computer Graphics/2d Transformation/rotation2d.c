#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

#define PI 3.14159

//line 1
int a1=400;
int b1=200;

// line 2
int c1 = 300;
int d1 = 400;

// line3
int e1 = 500;
int f1 = 400;

double result[3][3];

float degree = 60.0f; 
float rad = degree * (PI/180.0f);

double rotation_matrix[3][3] = {
{cos(rad), -sin(rad), 0},
{sin(rad), cos(rad), 0},
{0,0,1},
};

int originalMatrix[3][3] = {
  {a1,c1,e1},
  {b1,d1,f1},
  {1,1,1}
};

void matrixmultiplication(double m1[3][3], int m2[3][3]){

   for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = 0;

            for (int k = 0; k < 3; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }

            printf("%lf\t", result[i][j],i,j);
        }

        printf("\n");
    }
}

void rotation2D(){

  matrixmultiplication(rotation_matrix, originalMatrix);

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

  initwindow(700,700,"Rotation");

  line(a1,b1,c1,d1);
  line(c1,d1,e1,f1);
  line(e1,f1,a1,b1);


  rotation2D();

  getch();
  closegraph();
  return 0;
}
